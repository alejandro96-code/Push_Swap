#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->first_node;
    
    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}

int get_min_position(t_stack *stack)
{
    t_node *current;
    int min;
    int pos;
    int min_pos;

    if (!stack->first_node)
        return (-1);
    current = stack->first_node;
    min = current->value;
    pos = 0;
    min_pos = 0;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (min_pos);
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

int get_max(t_stack *stack)
{
    t_node *current;
    int max;

    if (!stack->first_node)
        return (0);
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
    int max_num;
    int max_bits;
    int size;
    int i;
    int j;
    int num;

    size = stack_size(*a);
    max_num = size - 1;
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        ++max_bits;
    
    for (i = 0; i < max_bits; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            num = (*a)->first_node->value;
            if ((num >> i) & 1)
                rotate(*a, 'a');
            else
                push(*a, *b, 'b');
        }
        while ((*b)->first_node)
            push(*b, *a, 'a');
    }
}
