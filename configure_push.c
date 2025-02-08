#include "push_swap.h"

void push(t_stack *src, t_stack *dest, char stack)
{
    t_node *temp;

    if (src->first_node == NULL)
        return;

    temp = src->first_node;
    src->first_node = src->first_node->next;
    temp->next = dest->first_node;
    dest->first_node = temp;
    
    if (stack == 'a')
        write(1, "pa\n", 3);
    else if (stack == 'b')
        write(1, "pb\n", 3);
}