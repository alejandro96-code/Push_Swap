#include "push_swap.h"

void swap(t_stack *stack, char stack_name)
{
    t_node *first;
    t_node *second;

    if (stack->first_node == NULL || stack->first_node->next == NULL)
        return;

    first = stack->first_node;
    second = first->next;
    first->next = second->next;
    second->next = first;
    stack->first_node = second;

    if (stack_name == 'a')
        write(1, "sa\n", 3);
    else if (stack_name == 'b')
        write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    swap(a, 'x');  // Usamos 'x' para no imprimir el mensaje
    swap(b, 'x');
    write(1, "ss\n", 3);
}