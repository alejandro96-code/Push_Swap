Push_swap
Este proyecto consiste en ordenar datos en un stack con un conjunto limitado de instrucciones y la menor cantidad de movimientos posibles.
🎯 Objetivo del Proyecto
El objetivo es ordenar una lista de números enteros usando dos stacks (A y B) y un conjunto específico de operaciones, tratando de usar la menor cantidad de movimientos posible.
🛠️ Operaciones Permitidas

sa: swap a - intercambia los dos primeros elementos del stack a
sb: swap b - intercambia los dos primeros elementos del stack b
ss: sa y sb al mismo tiempo
pa: push a - toma el primer elemento de b y lo pone encima de a
pb: push b - toma el primer elemento de a y lo pone encima de b
ra: rotate a - desplaza hacia arriba todos los elementos del stack a una posición
rb: rotate b - desplaza hacia arriba todos los elementos del stack b una posición
rr: ra y rb al mismo tiempo
rra: reverse rotate a - desplaza hacia abajo todos los elementos del stack a una posición
rrb: reverse rotate b - desplaza hacia abajo todos los elementos del stack b una posición
rrr: rra y rrb al mismo tiempo

💡 Ejemplo de Funcionamiento
Veamos un ejemplo más complejo con 12 números: 64 34 21 89 45 12 78 23 56 92 11 67

Estado inicial:

CopyStack A: 64 34 21 89 45 12 78 23 56 92 11 67
Stack B: (vacío)

El programa detecta que hay más de 5 números y utiliza big_sort:
Primero, encuentra el rango de valores:

Copymin = 11
max = 92
chunk_size = (92 - 11) / 4 ≈ 20

División en chunks:


Chunk 1: 11-31
Chunk 2: 32-52
Chunk 3: 53-73
Chunk 4: 74-92


Procesamiento del primer chunk (11-31):

Copyrb (12)
pb  
Stack A: 64 34 89 45 78 23 56 92 67
Stack B: 21 12

rb (23)
pb
Stack A: 64 34 89 45 78 56 92 67
Stack B: 23 21 12

Procesamiento del segundo chunk (32-52):

Copypb
Stack A: 64 89 45 78 56 92 67
Stack B: 34 23 21 12

rb (45)
pb
Stack A: 64 89 78 56 92 67
Stack B: 45 34 23 21 12

Procesamiento del tercer chunk (53-73):

Copypb
Stack A: 89 78 92 67
Stack B: 64 56 45 34 23 21 12

pb
Stack A: 89 78 92
Stack B: 67 64 56 45 34 23 21 12

Procesamiento del último chunk (74-92):

Copypb
Stack A: 89 92
Stack B: 78 67 64 56 45 34 23 21 12

pb
pb
Stack A: (vacío)
Stack B: 92 89 78 67 64 56 45 34 23 21 12

Ordenamiento final (sort_b_stack):
El programa ahora encuentra el máximo en B y lo envía a A repetidamente:

Copypa (92)
pa (89)
pa (78)
pa (67)
...

Estado final:

CopyStack A: 11 12 21 23 34 45 56 64 67 78 89 92
Stack B: (vacío)
🔍 Detalles de Implementación Importantes
Manejo de Diferentes Tamaños
El programa utiliza diferentes estrategias según el tamaño de entrada:

Para 2 números: Simple swap si es necesario
Para 3 números: Algoritmo específico para 3 números
Para 4-5 números: Algoritmo que separa los números más pequeños a B
Para >5 números: Algoritmo de chunks

Algoritmo para Grandes Conjuntos (big_sort)
Este es uno de los puntos más complejos del programa. El algoritmo funciona así:

División en Chunks: La función split_into_chunks divide los números en 4 segmentos:

cCopychunk_size = (max - min) / 4;

Ordenamiento por Chunks: Cada chunk se procesa de manera que:

Los números más pequeños del chunk van a la parte inferior de B
Los números más grandes del chunk van a la parte superior de B
Esto crea una semi-ordenación en B


Ordenamiento Final: sort_b_stack devuelve los números a A en orden:

Encuentra el máximo en B
Lo coloca en la parte superior usando la rotación más eficiente
Lo empuja a A



Optimizaciones Clave

Rotación Eficiente:

cCopyif (get_max_position(*b) <= stack_size(*b) / 2)
    rotate(*b, 'b');
else
    reverse_rotate(*b, 'b');
Este código elige la dirección de rotación más corta.

Manejo de Memoria:

cCopyvoid free_stack(t_stack *stack)
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
Libera toda la memoria asignada, evitando memory leaks.
🚀 Compilación y Uso
bashCopymake
./push_swap 64 34 21 89 45 12 78 23 56 92 11 67
El programa imprimirá la lista de operaciones necesarias para ordenar los números.
⚠️ Manejo de Errores
El programa verifica:

Números duplicados
Números no válidos
Overflow/underflow de integers
Si la lista ya está ordenada

En caso de error, imprime "Error" en la salida de error estándar.
📝 Complejidad

Para 3 números: Máximo 2-3 operaciones
Para 5 números: Máximo 12 operaciones
Para 100 números: ~700 operaciones (varía según implementación)
Para 500 números: ~5500 operaciones (varía según implementación)