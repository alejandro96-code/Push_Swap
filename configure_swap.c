#include "push_swap.h"

void swap(t_stack *stack, char stack_name)
{
    t_stack *first;
    t_stack *second;

    if (stack && stack->next)
    {
        first = stack;
        second = stack->next;
        first->next = second->next;
        second->next = first;
        stack = second;
    }
}
