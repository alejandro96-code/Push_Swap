#include "push_swap.h"

void sort_chunk(t_stack **a, t_stack **b, int min, int max)
{
    int initial_size = stack_size(*a);
    int rotated = 0;

    while (*a && (*a)->first_node && rotated < initial_size)
    {
        if ((*a)->first_node->value >= min && (*a)->first_node->value <= max)
        {
            push(*a, *b, 'b');
            if ((*b)->first_node->value < (min + max) / 2)
                rotate(*b, 'b');
        }
        else
        {
            rotate(*a, 'a');
            rotated++;
        }
    }
}

void split_into_chunks(t_stack **a, t_stack **b, int min, int max)
{
    int chunk_size;
    int i;

    chunk_size = (max - min) / 4;
    i = 0;
    while (i < 4)
    {
        sort_chunk(a, b, min + (i * chunk_size), min + ((i + 1) * chunk_size));
        i++;
    }
    while (*a && (*a)->first_node)
    {
        push(*a, *b, 'b');
    }
}

void sort_b_stack(t_stack **a, t_stack **b)
{
    int max;

    while (*b && (*b)->first_node)
    {
        max = get_max_value(*b);
        while ((*b)->first_node->value != max)
        {
            if (get_max_position(*b) <= stack_size(*b) / 2)
                rotate(*b, 'b');
            else
                reverse_rotate(*b, 'b');
        }
        push(*b, *a, 'a');
    }
}

void big_sort(t_stack **a, t_stack **b)
{
    int size;
    int min;
    int max;

    size = stack_size(*a);
    if (size <= 5)
    {
        sort_five(*a, *b);
        return;
    }
    min = get_min_value(*a);
    max = get_max_value(*a);
    split_into_chunks(a, b, min, max);
    sort_b_stack(a, b);
}