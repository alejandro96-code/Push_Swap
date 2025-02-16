#include "push_swap.h"

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