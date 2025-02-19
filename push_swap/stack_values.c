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
int get_max_position(t_stack *stack)
{
    t_node *current;
    int max;
    int pos;
    int max_pos;

    if (!stack->first_node)
        return (-1);
    current = stack->first_node;
    max = current->value;
    pos = 0;
    max_pos = 0;
    while (current)
    {
        if (current->value > max)
        {
            max = current->value;
            max_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (max_pos);
}