#include "push_swap.h"

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

int init_stack(t_stack **stack)
{
    *stack = malloc(sizeof(t_stack));
    if (!*stack)
        return (0);
    (*stack)->first_node = NULL;
    return (1);
}

int add_number(t_stack *stack, char *str)
{
    long    num;
    t_node  *new_node;
    t_node  *temp;

    if (!is_number(str))
        return (0);
    num = ft_atol(str);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->value = (int)num;
    new_node->next = NULL;
    if (!stack->first_node)
        stack->first_node = new_node;
    else
    {
        temp = stack->first_node;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
    return (1);
}

int process_arguments(int argc, char **argv, t_stack *a)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!add_number(a, argv[i]))
            return (0);
        i++;
    }
    if (check_duplicates(a))
        return (0);
    return (1);
}
