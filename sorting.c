#include "push_swap.h"

void sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

    if (!a->first_node || !a->first_node->next || !a->first_node->next->next)
        return;
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

static void push_small_to_b(t_stack *a, t_stack *b, int max_push)
{
    int pushed = 0;
    int min;

    while (pushed < max_push)
    {
        min = get_min_value(a);
        int moves = 0;
        while (a->first_node->value != min)
        {
            if (get_min_position(a) <= stack_size(a) / 2)
                rotate(a, 'a');
            else
                reverse_rotate(a, 'a');
            
            moves++;
            if (moves > stack_size(a))
            {  
                write(2, "Error: infinite loop\n", 21);
                return;
            }
        }
        push(a, b, 'b');
        pushed++;
    }
}

void sort_five(t_stack *a, t_stack *b)
{
    int size;

    size = stack_size(a);
    if (size <= 3)
    {
        sort_three(a);
        return;
    }
    push_small_to_b(a, b, size - 3);
    sort_three(a);
    while (b->first_node)
        push(b, a, 'a');
}

static void sort_chunk(t_stack **a, t_stack **b, int min, int max)
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
int get_max_position(t_stack *stack)
{
    t_node *current;
    int max;
    int pos;
    int max_pos;

    if (!stack->first_node)
        return (-1);
    current = stack->first_node;
    max = current->value;
    pos = 0;
    max_pos = 0;
    while (current)
    {
        if (current->value > max)
        {
            max = current->value;
            max_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (max_pos);
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
