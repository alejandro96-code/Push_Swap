#include "push_swap.h"

void rotate(t_stack *stack, char stack_name)
{
    t_node *temp;
    t_node *last;

    if (stack->first_node == NULL || stack->first_node->next == NULL)
        return;

    temp = stack->first_node;
    stack->first_node = stack->first_node->next;
    temp->next = NULL;
    last = stack->first_node;
    while (last->next)
        last = last->next;
    last->next = temp;

    if (stack_name == 'a')
        write(1, "ra\n", 3);
    else if (stack_name == 'b')
        write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a, 'x');  // Usamos 'x' para no imprimir el mensaje
    rotate(b, 'x');
    write(1, "rr\n", 3);
}