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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    if (!init_stack(&a) || !init_stack(&b))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (!process_arguments(argc, argv, a))
    {
        free_stack(a);
        free_stack(b);
        return (1);
    }
    if (is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        printf("The stack is already sorted.\n");
        return (0);
    }

    if (stack_size(a) == 2)
        swap(a, 'a');
    else if (stack_size(a) == 3)
        sort_three(a);
    else if (stack_size(a) <= 5)
        sort_five(a, b);
    else
        big_sort(&a, &b);

    // Imprimir el estado final del stack A
    printf("\nFinal state of stack A:\n");
    print_stack(a, 'A');

    // Verificar si la pila está ordenada correctamente
    if (is_sorted(a))
        printf("✅ Sorting completed successfully!\n");
    else
        printf("❌ Sorting failed. The stack is not sorted correctly.\n");

    free_stack(a);
    free_stack(b);
    return (0);
}
