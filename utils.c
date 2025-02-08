#include "push_swap.h"

void stack_push(t_stack **stack, int value)
{
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

int stack_size(t_stack *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int *stack_to_sorted_array(t_stack *stack)
{
    int *array;
    int i = 0;

    int size = stack_size(stack);
    array = malloc(sizeof(int) * size);
    if (!array)
        return NULL;
    while (stack)
    {
        array[i++] = stack->value;
        stack = stack->next;
    }
    // Ordenar el array
    return array;
}
