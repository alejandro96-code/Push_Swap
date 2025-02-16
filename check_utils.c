#include "push_swap.h"

int is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int check_duplicates(t_stack *stack)
{
    t_node *current;
    t_node *check;

    current = stack->first_node;
    while (current)
    {
        check = current->next;
        while (check)
        {
            if (current->value == check->value)
                return (1);
            check = check->next;
        }
        current = current->next;
    }
    return (0);
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