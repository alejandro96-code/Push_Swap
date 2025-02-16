#include "push_swap.h"

void push_small_to_b(t_stack *a, t_stack *b, int max_push)
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