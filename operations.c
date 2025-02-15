#include "push_swap.h"

void swap(t_stack *stack, char stack_name, t_moves *moves)
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
    {
        write(1, "sa\n", 3);
        moves->moves[moves->count] = "sa";  // Almacenar el movimiento
        moves->count++;
    }

    else if (stack_name == 'b')
    {
        write(1, "sb\n", 3);
        moves->moves[moves->count] = "sb";  // Almacenar el movimiento
        moves->count++;
    }
}

void push(t_stack *src, t_stack *dest, char stack, t_moves *moves)
{
    t_node *temp;

    if (!src->first_node)
        return;
    temp = src->first_node;
    src->first_node = src->first_node->next;
    temp->next = dest->first_node;
    dest->first_node = temp;
    if (stack == 'a')
    {
        write(1, "pa\n", 3);
        moves->moves[moves->count] = "pa";  // Almacenar el movimiento
        moves->count++;
    }  
    else if (stack == 'b')
    {
        write(1, "pb\n", 3);
        moves->moves[moves->count] = "pb";  // Almacenar el movimiento
        moves->count++;
    }
        
}

void rotate(t_stack *stack, char stack_name, t_moves *moves)
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
    {
        write(1, "ra\n", 3);
        moves->moves[moves->count] = "ra";  // Almacenar el movimiento
        moves->count++;
    }    
    else if (stack_name == 'b')
    {
        write(1, "rb\n", 3);
        moves->moves[moves->count] = "rb";  // Almacenar el movimiento
        moves->count++;
    }
}

void reverse_rotate(t_stack *stack, char stack_name, t_moves *moves)
{
    t_node *last;
    t_node *second_last;

    if (!stack->first_node || !stack->first_node->next)
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
    {
        write(1, "rra\n", 4);
        moves->moves[moves->count] = "rra";  // Almacenar el movimiento
        moves->count++;
    }

    else if (stack_name == 'b')
    {
        write(1, "rrb\n", 4);
        moves->moves[moves->count] = "rrb";  // Almacenar el movimiento
        moves->count++;
    }
}