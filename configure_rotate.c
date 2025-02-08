#include "push_swap.h"

void rotate(t_stack **stack, char stack_name)
{
    t_stack *first;
    t_stack *last;

    if (*stack && (*stack)->next)
    {
        first = *stack;
        *stack = (*stack)->next;
        first->next = NULL;
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = first;
    }
}
