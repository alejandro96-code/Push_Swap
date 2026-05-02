# Push_swap

Este proyecto ordena una lista de enteros usando dos stacks (A y B) y un
conjunto limitado de operaciones, buscando el menor numero de movimientos.

---

## Operaciones permitidas

| Operacion | Descripcion |
|-----------|-------------|
| `sa` | swap a: intercambia los dos primeros de A |
| `sb` | swap b: intercambia los dos primeros de B |
| `pa` | push a: mueve el primero de B a A |
| `pb` | push b: mueve el primero de A a B |
| `ra` | rotate a: el primero de A pasa al final |
| `rb` | rotate b: el primero de B pasa al final |
| `rr` | `ra` y `rb` a la vez |
| `rra` | reverse rotate a: el ultimo de A pasa al inicio |
| `rrb` | reverse rotate b: el ultimo de B pasa al inicio |
| `rrr` | `rra` y `rrb` a la vez |

Tambien esta permitida ss pero no la hemos implementado porque no la llegamos a usar.

---

## Compilacion y uso

```bash
make
./push_swap 3 2 1
```

Para verificar con el checker:

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

Para contar movimientos:

```bash
ARG="3 2 1"; ./push_swap $ARG | wc -l
```

---

## Como funciona (resumen claro)

1) **Parseo y validacion**
	- Se valida que todos sean numeros, que no haya duplicados y no haya overflow. (el int sea mayor que MAXINT)
	- Si ya esta ordenado, termina.

2) **Analizamos los casos pequeños (cadena de 2 a 5 numeros)**
	- Si ha 2 numeros y estan desordenados: usa `sa`.
	- Si hay 3 numeros se usa la funcion: `sort_three`.
	- Si hay 4 o 5 numeros se usa la funcion `sort_five` y si hay necesidad la `sort_three`
	- Si hay mas 6 numeros a ordenar se usa el algortimo turco

3) **Casos grandes (algoritmo turco)**
	- Se asigna un index a cada valor segun su orden real. Es decir el numero mas bajo tendra el index 0, el siguiente el 1, el siguiente el 2...
	- Se usa la funcion `push_to_b` para empujar todos los numeros a B exceptuando 3. En el caso de que el chunk
	  sea menor o igual a 100 se usa un chunk de 15, si es mayor se usa un chunk de 30.
	- Se calcula el coste para insertar cada elemento de B en su posicion correcta en A. Se elige siempre el mas barato y se aplican rotaciones combinadas (`rr`/`rrr`) cuando conviene.
	- Se rota A al final para dejar el minimo arriba.

---

## Ejemplo sort_three

Entrada:

```
STACK A: [2 3 1]
STACK B: []
```
Funcion:
1) `rra` mueve el 1 al inicio y queda `1 2 3`.

Salida posible:

### 1)
```
STACK A: [1 2 3]
STACK B: []
```

## Ejemplo sort_five

Entrada:
```
STACK A: [3 5 1 4 2]
STACK B: []
```

Funcion:
 1) Empuja los dos menores a B con `pb`.
 2) Ordena los 3 restantes con `sort_three`.
 3) Devuelve con `pa pa`.

Salida posible:

### 1)
```
STACK A: [3 5 4 ]
STACK B: [1 2]

```

### 2)
```
STACK A: [3 4 5 ]
STACK B: [1 2]
```

### 3)
```
STACK A: [1 2 3 4 5 ]
STACK B: []
```

## Ejemplo grande (Algoritmo turco)

Entrada:

Entrada (20 numeros):

```
42 7 19 3 25 14 2 30 11 5 27 1 9 21 4 16 8 24 6 18
```

### 1) Indexado
Se ordenan los valores y se asignan indices 0..19:

```
1->0 2->1 3->2 4->3 5->4 6->5 7->6 8->7 9->8 11->9
14->10 16->11 18->12 19->13 21->14 24->15 25->16 27->17 30->18 42->19
```

Ahora cada nodo guarda su `index`.

### 2) Push a B por chunks
En `push_swap_turco` para size <= 100 se usa `chunk = 15`.
La variable `cont` empieza en 0 y se empuja a B asi:

- Si `index <= cont`: `pb` y luego `rb` (para dejar indices muy bajos mas abajo).
- Si `index <= cont + chunk`: solo `pb`.
- Si no: `ra` (rotas A para buscar otro candidato).

Con 20 numeros, el primer bloque efectivo es indices 0..15.
Eso deja la mayor parte en B y 3 nodos en A.

```
Stack A: [6, 18, 42]
Stack B: [24, 21, 27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8]
```

### 3) Ordenar los 3 restantes en A
Se usa `sort_three` para dejar A ordenada con esos 3.

### 4) Calcular costos para cada nodo en B
Para cada nodo de B se calcula:

- `target_pos` en A: donde debe insertarse para mantener orden.
- `cost_a`: cuantas rotaciones necesita A para llegar a `target_pos`.
- `cost_b`: cuantas rotaciones necesita B para subir ese nodo.

Si ambos costos tienen el mismo signo, se pueden combinar con `rr` o `rrr`.
Eso reduce movimientos.

Como iria quedando:

```
Stack A: [6, 18, 42]
Stack B: [24, 21, 27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8]
```

```
Stack A: [42, 6, 18]
Stack B: [21, 27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24]
```

```
Stack A: [42, 6, 18, 21]
Stack B: [27, 11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24]
```

```
Stack A: [42, 6, 18, 21, 27]
Stack B: [11, 30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24]
```

```
Stack A: [42, 6, 18, 21, 27]
Stack B: [30, 14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11]
```

```
Stack A: [30, 42, 6, 18, 21, 27]
Stack B: [14, 25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11]
```

```
Stack A: [30, 42, 6, 18, 21, 27]
Stack B: [25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```

 - Aqui sabemos que el siguiente numero es el 25 y es mas barato mover le 27 a priemra posicion y despues insertar el 25 en primera posicion

```
Stack A: [27, 30, 42, 6, 18, 21]
Stack B: [25, 19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]

Stack A: [25, 27, 30, 42, 6, 18, 21]
Stack B: [19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```
y con el siguiente (el 19) pasas lo mismo

```
Stack A: [21, 25, 27, 30, 42, 6, 18]
Stack B: [19, 7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]

Stack A: [19, 21, 25, 27, 30, 42, 6, 18]
Stack B: [7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```

Y ahora como sabemos que el index del ultimo numero es el anterior al primer numero de la fila debemos
pasarlo a primera posicion antes de continuar

```
Stack A: [18, 19, 21, 25, 27, 30, 42, 6]
Stack B: [7, 3, 2, 5, 1, 9, 4, 16, 8, 24, 11, 14]
```

Se repite hasta vaciar B.

### 6) Rotacion final

Es posbile que cuando termine el bucle se nos quede asi:

```
Stack A: [2, 3, 4, 5, 6, 7, 8, 9, 11, 14, 16, 18, 19, 21, 24, 25, 27, 30, 42, 1]
Stack B; []
```
usaremos `final_rotate` sube el indice minimo a la cima.

Resultado: A ordenada de menor a mayor, B vacia.

```
Stack A: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 14, 16, 18, 19, 21, 24, 25, 27, 30, 42]
Stack B; []
```
---
