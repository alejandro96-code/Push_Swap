#include "push_swap.h"

static int add_number(t_stack *stack, char *str)
{
    long    num;
    t_node  *new_node;

    if (!is_number(str))
        return (0);
    num = ft_atol(str);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (0);
    new_node->value = (int)num;
    new_node->next = stack->first_node;
    stack->first_node = new_node;
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

void print_stack(t_stack *stack, char name)
{
    t_node *current = stack->first_node;

    printf("Stack %c:\n", name);
    printf("---------\n");
    while (current)
    {
        printf("  %d\n", current->value);
        current = current->next;
    }
    printf("---------\n");
}

void print_final_stack(t_stack *stack)
{
    t_node *current = stack->first_node;
    while (current)
    {
        char buffer[12];
        int len = sprintf(buffer, "%d\n", current->value);
        write(1, buffer, len);
        current = current->next;
    }
}

void print_moves(t_moves *moves)
{
    for (int i = 0; i < moves->count; i++)
    {
        write(1, moves->moves[i], 3);
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_moves moves;

    moves.count = 0;
    if (argc < 2)
        return (0);
    if (!init_stack(&a) || !init_stack(&b) || !init_moves(&moves, 1000) || !process_arguments(argc, argv, a))
        return (write(2, "Error\n", 6), 1);
    if (is_sorted(a))
        return (free_stack(a), free_stack(b), 0);
    if (stack_size(a) == 2)
        swap(a, 'a', &moves);
    else if (stack_size(a) == 3)
        sort_three(a, &moves);
    else if (stack_size(a) <= 5)
        sort_five(a, b, &moves);
    else
        big_sort(&a, &b, &moves);
    print_moves(&moves);
    print_final_stack(a);
    free_stack(a);
    free_stack(b);
    return (0);
}
