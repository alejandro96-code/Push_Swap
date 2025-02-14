#include "push_swap.h"

void sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

    first = a->first_node->value;
    second = a->first_node->next->value;
    third = a->first_node->next->next->value;

    if (first > second && second < third && first < third)
        swap(a, 'a');
    else if (first > second && second > third)
    {
        swap(a, 'a');
        reverse_rotate(a, 'a');
    }
    else if (first > second && second < third && first > third)
        rotate(a, 'a');
    else if (first < second && second > third && first < third)
    {
        swap(a, 'a');
        rotate(a, 'a');
    }
    else if (first < second && second > third && first > third)
        reverse_rotate(a, 'a');
}

void sort_five(t_stack *a, t_stack *b)
{
    int size;
    int min_pos;

    size = stack_size(a);
    while (size > 3)
    {
        min_pos = get_min_position(a);
        while (min_pos > 0)
        {
            if (min_pos <= size / 2)
                rotate(a, 'a');
            else
                reverse_rotate(a, 'a');
            min_pos = get_min_position(a);
        }
        push(a, b, 'b');
        size--;
    }
    sort_three(a);
    while (b->first_node)
        push(b, a, 'a');
}

static void push_chunk(t_stack **a, t_stack **b, int chunk_min, int chunk_max)
{
    int i;
    int size;

    size = stack_size(*a);
    i = 0;
    while (i < size && (*a)->first_node)
    {
        if ((*a)->first_node->value >= chunk_min && 
            (*a)->first_node->value <= chunk_max)
        {
            push(*a, *b, 'b');
            if ((*b)->first_node->value < chunk_max)
                rotate(*b, 'b');
        }
        else
            rotate(*a, 'a');
        i++;
    }
}

static int find_next_max(t_stack *stack)
{
    t_node *current;
    int max;

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

void big_sort(t_stack **a, t_stack **b)
{
    int size;
    int min;
    int max;
    int chunk_size;
    int i;

    size = stack_size(*a);
    min = (*a)->first_node->value;
    max = find_next_max(*a);
    chunk_size = (size <= 100) ? size / 5 : size / 11;

    for (i = 0; i < 5; i++)
    {
        int chunk_min = min + (i * chunk_size);
        int chunk_max = chunk_min + chunk_size - 1;
        push_chunk(a, b, chunk_min, chunk_max);
    }

    while ((*b)->first_node)
    {
        int curr_max = find_next_max(*b);
        t_node *current = (*b)->first_node;
        int pos = 0;
        while (current && current->value != curr_max)
        {
            pos++;
            current = current->next;
        }
        while ((*b)->first_node->value != curr_max)
        {
            if (pos <= stack_size(*b) / 2)
                rotate(*b, 'b');
            else
                reverse_rotate(*b, 'b');
        }
        push(*b, *a, 'a');
    }
}