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

long ft_atol(const char *str)
{
    long    result;
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
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
    return (1);
}