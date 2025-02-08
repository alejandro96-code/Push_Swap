#include "push_swap.h"
#include <stdlib.h>

// Función para obtener el tamaño de la pila
int stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->first_node;
    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}

// Función para ordenar tres elementos en la pila
void sort_three(t_stack *a)
{
    if (a == NULL || a->first_node == NULL || a->first_node->next == NULL)
        return;

    if (a->first_node->value > a->first_node->next->value)
        swap(a, 'a');

    if (a->first_node->next->value > a->first_node->next->next->value)
    {
        swap(a, 'a');
        rotate(a, 'a');
    }
}

// Función para ordenar cinco elementos en las pilas 'a' y 'b'
void sort_five(t_stack *a, t_stack *b)
{
    while (stack_size(a) > 3)
        push(a, b, 'b');
    sort_three(a);
    while (stack_size(b) > 0)
        push(b, a, 'a');
}

// Función auxiliar para obtener el array ordenado de la pila
int *sort_stack(t_stack *a)
{
    int *sorted_array;
    int size;
    t_node *current;
    int i;

    size = stack_size(a);
    sorted_array = (int *)malloc(sizeof(int) * size);
    if (!sorted_array)
        return (NULL);
    
    current = a->first_node;
    i = 0;
    while (current)
    {
        sorted_array[i++] = current->value;
        current = current->next;
    }
    qsort(sorted_array, size, sizeof(int), compare_ints);
    return sorted_array;
}

// Función para comparar dos enteros (para usar con qsort)
int compare_ints(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Función para determinar el tamaño de los chunks para el "big sort"
int determine_chunk_size(t_stack *a)
{
    int size = stack_size(a);
    if (size <= 100)
        return size / 10;
    return size / 20;
}

// Función para realizar el "big sort" en las pilas 'a' y 'b'
void big_sort(t_stack **a, t_stack **b)
{
    int *sorted_array;
    int i;
    int chunk_size;

    sorted_array = sort_stack(*a);
    if (!sorted_array)
        return;
    
    chunk_size = determine_chunk_size(*a);
    i = 0;
    while (i < stack_size(*a))
    {
        if ((*a)->first_node->value <= sorted_array[i])
            push(*a, *b, 'b');
        else if (stack_size(*b) > 1 && (*b)->first_node->value < sorted_array[i - chunk_size])
            rotate(*b, 'b');
        else
            rotate(*a, 'a');
        i++;
    }

    free(sorted_array);
}