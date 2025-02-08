#include "push_swap.h"

void reverse_rotate(t_stack *stack, char stack_name)
{
    t_node *last;
    t_node *second_last;

    if (stack->first_node == NULL || stack->first_node->next == NULL)
        return;
    
    last = stack->first_node;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = stack->first_node;
    stack->first_node = last;

    if (stack_name == 'a')
        write(1, "rra\n", 4);
    else if (stack_name == 'b')
        write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a, 'x');  // Usamos 'x' para no imprimir el mensaje
    reverse_rotate(b, 'x');
    write(1, "rrr\n", 4);
}