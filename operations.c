#include "push_swap.h"

void swap(t_stack *stack, char stack_name)
{
    t_node *first;
    t_node *second;

    if (!stack->first_node || !stack->first_node->next)
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

void push(t_stack *src, t_stack *dest, char stack)
{
    t_node *temp;

    if (!src->first_node)
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

void rotate(t_stack *stack, char stack_name)
{
    t_node *temp;
    t_node *last;

    if (!stack->first_node || !stack->first_node->next)
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

void reverse_rotate(t_stack *stack, char stack_name)
{
    t_node *last;
    t_node *second_last;

    // Si la pila está vacía o tiene solo un elemento, no se realiza ninguna rotación
    if (!stack->first_node || !stack->first_node->next)
        return;

    // Inicialización de punteros
    last = stack->first_node;
    second_last = NULL;

    // Imprimir estado antes de la rotación
    //printf("Estado inicial de la pila %c: ", stack_name);
    t_node *temp = stack->first_node;
    while (temp)
    {
        //printf("%d ", temp->value);
        temp = temp->next;
    }
    //printf("\n");

    // Recorrer la lista para encontrar el último y penúltimo nodo
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    // Ahora `last` es el último nodo y `second_last` es el penúltimo
    if (second_last)
    {
        second_last->next = NULL;   // El penúltimo nodo ya no debe apuntar al último
        last->next = stack->first_node; // El último nodo apunta al principio de la pila
        stack->first_node = last;    // Actualizamos el primer nodo de la pila
    }

    // Imprimir estado después de la rotación
    //printf("Estado después de la rotación %c: ", stack_name);
    temp = stack->first_node;
    while (temp)
    {
        //printf("%d ", temp->value);
        temp = temp->next;
    }
    //printf("\n");

    // Imprimir la operación realizada
    if (stack_name == 'a')
        write(1, "rra\n", 4);
    else if (stack_name == 'b')
        write(1, "rrb\n", 4);
}
