#include "push_swap.h"

int get_min_value(t_stack *stack)
{
    t_node *current;
    int min;

    if (!stack->first_node)
        return (0);
    current = stack->first_node;
    min = current->value;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int get_max_value(t_stack *stack)
{
    t_node *current;
    int max;

    if (!stack->first_node)
        return (0);
    current = stack->first_node;
    max = current->value;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int get_min_position(t_stack *stack)
{
    t_node *current;
    int min;
    int pos;
    int min_pos;

    if (!stack->first_node)
        return (-1);
    current = stack->first_node;
    min = current->value;
    pos = 0;
    min_pos = 0;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (min_pos);
}

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = stack->first_node;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

int stack_size(t_stack *stack)
{
    int size;
    t_node *current;

    size = 0;
    current = stack->first_node;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->first_node)
        return (1);
    current = stack->first_node;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int init_stack(t_stack **stack)
{
    *stack = malloc(sizeof(t_stack));
    if (!*stack)
        return (0);
    (*stack)->first_node = NULL;
    (*stack)->move_count = 0;  // Inicializamos el contador
    return (1);
}
