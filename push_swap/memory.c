#include "push_swap.h"

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

long ft_atol(const char *str)
{
    long    result;
    int     sign;
    int     cont;

    result = 0;
    sign = 1;
    cont = 0;
    if (str[cont] == '-' || str[cont] == '+')
    {
        if (str[cont] == '-')
            sign = -1;
        cont++;
    }
    while (str[cont] >= '0' && str[cont] <= '9')
    {
        result = result * 10 + (str[cont] - '0');
        cont++;
    }
    return (result * sign);
}