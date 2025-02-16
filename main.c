#include "push_swap.h"

static int add_number(t_stack *stack, char *str)
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

static int process_arguments(int argc, char **argv, t_stack *a)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!add_number(a, argv[i]))
        {
            write(2, "Error\n", 6);
            return (0);
        }
        i++;
    }
    if (check_duplicates(a))
    {
        write(2, "Error\n", 6);
        return (0);
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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    if (!init_stack(&a) || !init_stack(&b) || !process_arguments(argc, argv, a))
        return (write(2, "Error\n", 6), 1);
    if (is_sorted(a))
        return (free_stack(a), free_stack(b), 0);
    if (stack_size(a) == 2)
        swap(a, 'a');
    else if (stack_size(a) == 3)
        sort_three(a);
    else if (stack_size(a) <= 5)
        sort_five(a, b);
    else
        big_sort(&a, &b);
    free_stack(a);
    free_stack(b);
    return (0);
}
