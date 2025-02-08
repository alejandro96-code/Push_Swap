#include "push_swap.h"

void reverse_rotate(t_stack **stack, char stack_name)
{
    t_stack *temp;
    t_stack *last;

    if (*stack && (*stack)->next)
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        last = temp;
        temp = *stack;
        while (temp->next != last)
            temp = temp->next;
        temp->next = NULL;
        last->next = *stack;
        *stack = last;
    }
}
