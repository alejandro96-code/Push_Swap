#include "push_swap.h"

void push(t_stack **a, t_stack **b, char stack)
{
    t_stack *temp;

    if (stack == 'a' && *b)
    {
        temp = *b;
        *b = (*b)->next;
        temp->next = *a;
        *a = temp;
    }
    else if (stack == 'b' && *a)
    {
        temp = *a;
        *a = (*a)->next;
        temp->next = *b;
        *b = temp;
    }
}
