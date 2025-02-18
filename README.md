# Push_swap

Este proyecto consiste en ordenar datos en un stack con un conjunto limitado de instrucciones y la menor cantidad de movimientos posibles.

## Objetivo del Proyecto

El objetivo es ordenar una lista de números enteros usando dos stacks (A y B) y un conjunto específico de operaciones, tratando de usar la menor cantidad de movimientos posible.

## Operaciones Permitidas

| Operación | Descripción |
|-----------|-------------|
| `sa` | swap a - intercambia los dos primeros elementos del stack a |
| `sb` | swap b - intercambia los dos primeros elementos del stack b |
| `ss` | sa y sb al mismo tiempo |
| `pa` | push a - toma el primer elemento de b y lo pone encima de a |
| `pb` | push b - toma el primer elemento de a y lo pone encima de b |
| `ra` | rotate a - desplaza hacia arriba todos los elementos del stack a una posición |
| `rb` | rotate b - desplaza hacia arriba todos los elementos del stack b una posición |
| `rr` | ra y rb al mismo tiempo |
| `rra` | reverse rotate a - desplaza hacia abajo todos los elementos del stack a una posición |
| `rrb` | reverse rotate b - desplaza hacia abajo todos los elementos del stack b una posición |
| `rrr` | rra y rrb al mismo tiempo |

## Ejemplo de Funcionamiento

Veamos un ejemplo complejo con 12 números: `64 34 21 89 45 12 78 23 56 92 11 67`

1. Estado inicial:
```
Stack A: 64 34 21 89 45 12 78 23 56 92 11 67
Stack B: (vacío)
```

2. El programa detecta que hay más de 5 números y utiliza big_sort:

3. Primero, encuentra el rango de valores:
```
min = 11
max = 92
chunk_size = (92 - 11) / 4 ≈ 20
```

4. División en chunks:
```
Chunk 1: 11-31
Chunk 2: 32-52
Chunk 3: 53-73
Chunk 4: 74-92
```

5. Procesamiento del primer chunk (11-31):
```
rb (12)
pb  
Stack A: 64 34 89 45 78 23 56 92 67
Stack B: 21 12

rb (23)
pb
Stack A: 64 34 89 45 78 56 92 67
Stack B: 23 21 12
```

6. Procesamiento del segundo chunk (32-52):
```
pb
Stack A: 64 89 45 78 56 92 67
Stack B: 34 23 21 12

rb (45)
pb
Stack A: 64 89 78 56 92 67
Stack B: 45 34 23 21 12
```

7. Procesamiento del tercer chunk (53-73):
```
pb
Stack A: 89 78 92 67
Stack B: 64 56 45 34 23 21 12

pb
Stack A: 89 78 92
Stack B: 67 64 56 45 34 23 21 12
```

8. Procesamiento del último chunk (74-92):
```
pb
Stack A: 89 92
Stack B: 78 67 64 56 45 34 23 21 12

pb
pb
Stack A: (vacío)
Stack B: 92 89 78 67 64 56 45 34 23 21 12
```

9. Estado final:
```
Stack A: 11 12 21 23 34 45 56 64 67 78 89 92
Stack B: (vacío)
```

## Análisis Detallado de Funciones

### Funciones de Operaciones Básicas

#### 1. swap
```c
void swap(t_stack *stack, char stack_name)
```
Intercambia los dos primeros elementos del stack. Verifica si hay al menos 2 elementos, guarda referencias a los dos primeros nodos, realiza el intercambio ajustando los punteros e imprime "sa\n" o "sb\n" según el stack.

#### 2. push
```c
void push(t_stack *src, t_stack *dest, char stack)
```
Mueve el primer elemento de un stack al otro. Verifica si el stack fuente tiene elementos, extrae el primer nodo del stack fuente, lo inserta al principio del stack destino e imprime "pa\n" o "pb\n" según la dirección.

#### 3. rotate
```c
void rotate(t_stack *stack, char stack_name)
```
Mueve el primer elemento al final del stack. Guarda el primer nodo, actualiza el primer nodo al siguiente, encuentra el último nodo, conecta el antiguo primer nodo al final e imprime "ra\n" o "rb\n".

#### 4. reverse_rotate
```c
void reverse_rotate(t_stack *stack, char stack_name)
```
Mueve el último elemento al principio del stack. Encuentra el último y penúltimo nodo, desconecta el último nodo, lo coloca al principio del stack e imprime "rra\n" o "rrb\n".

### Funciones de Ordenamiento

#### 1. sort_three
```c
void sort_three(t_stack *a)
```
Ordena exactamente 3 números de manera óptima. Identifica uno de los 5 casos posibles:
- Caso 1 (2,1,3): Solo swap
- Caso 2 (3,2,1): Swap y reverse rotate
- Caso 3 (3,1,2): Solo rotate
- Caso 4 (1,3,2): Swap y rotate
- Caso 5 (2,3,1): Solo reverse rotate

#### 2. sort_five
```c
void sort_five(t_stack *a, t_stack *b)
```
Ordena hasta 5 números enviando los dos números más pequeños a B, ordena los tres restantes en A usando sort_three y devuelve los números de B a A.

#### 3. big_sort
```c
void big_sort(t_stack **a, t_stack **b)
```
Ordena conjuntos grandes de números dividiendo los números en chunks, mueve los números a B de manera semi-ordenada y devuelve los números a A en orden.

### Funciones de Utilidad

#### 1. stack_size
```c
int stack_size(t_stack *stack)
```
Cuenta el número de elementos en un stack retornando el número de nodos.

#### 2. get_min_value y get_max_value
```c
int get_min_value(t_stack *stack)
int get_max_value(t_stack *stack)
```
Encuentra el valor mínimo/máximo en el stack recorriendo todo el stack y comparando valores.

#### 3. get_min_position y get_max_position
```c
int get_min_position(t_stack *stack)
int get_max_position(t_stack *stack)
```
Encuentra la posición del valor mínimo/máximo retornando el índice (empezando en 0) del valor buscado.

#### 4. check_duplicates
```c
int check_duplicates(t_stack *stack)
```
Verifica si hay números duplicados comparando cada número con todos los siguientes. Retorna 1 si hay duplicados, 0 si no.

### Funciones de Manejo de Chunks

#### 1. sort_chunk
```c
void sort_chunk(t_stack **a, t_stack **b, int min, int max)
```
Procesa un rango específico de números identificando números dentro del rango, moviéndolos a B y organizándolos según su valor (mayores arriba, menores abajo).

#### 2. split_into_chunks
```c
void split_into_chunks(t_stack **a, t_stack **b, int min, int max)
```
Divide y procesa todo el conjunto en chunks calculando el tamaño de cada chunk, procesando cada chunk secuencialmente y moviendo los números restantes a B.

## Optimizaciones Clave

### 1. Rotación Eficiente
```c
if (get_max_position(*b) <= stack_size(*b) / 2)
    rotate(*b, 'b');
else
    reverse_rotate(*b, 'b');
```
Este código elige la dirección de rotación más corta.

### 2. Manejo de Memoria
```c
void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;    
    current = stack->first_node;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
```
Libera toda la memoria asignada, evitando memory leaks.

## Compilación y Uso

```bash
make
./push_swap 64 34 21 89 45 12 78 23 56 92 11 67
```

El programa imprimirá la lista de operaciones necesarias para ordenar los números.

## Manejo de Errores

El programa verifica:
- Números duplicados
- Números no válidos
- Overflow/underflow de integers
- Si la lista ya está ordenada

En caso de error, imprime "Error" en la salida de error estándar.

## Complejidad

- Para 3 números: Máximo 2-3 operaciones
- Para 5 números: Máximo 12 operaciones
- Para 100 números: ~700 operaciones (varía según implementación)
- Para 500 números: ~5500 operaciones (varía según implementación)