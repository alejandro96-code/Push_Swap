#include "push_swap.h"

void push_swap(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);

    if (size <= 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
        big_sort(a, b); // Algoritmo optimizado para 100 números
}

void big_sort(t_stack **a, t_stack **b)
{
    int chunk_size = stack_size(*a) / 5; // Dividir en 5 grupos
    int *sorted_array = stack_to_sorted_array(*a);
    int i = 0;

    while (*a)
    {
        if ((*a)->value <= sorted_array[i])
        {
            push(b, a, 'b'); // configure_push.c
            if (stack_size(*b) > 1 && (*b)->value < sorted_array[i - chunk_size])
                rotate(b, 'b'); // configure_rotate.c
            i++;
        }
        else
            rotate(a, 'a'); // configure_rotate.c
    }
    insert_sorted_back(a, b, sorted_array);
    free(sorted_array);
}

void insert_sorted_back(t_stack **a, t_stack **b, int *sorted_array)
{
    while (*b)
    {
        int best_move = find_best_move(*a, *b, sorted_array);
        execute_best_move(a, b, best_move);
        push(a, b, 'a'); // configure_push.c
    }
}
