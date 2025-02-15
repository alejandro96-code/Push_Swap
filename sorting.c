#include "push_swap.h"

void sort_three(t_stack *a, t_moves *moves)
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
        swap(a, 'a', moves);
    else if (first > second && second > third)
    {
        swap(a, 'a', moves);
        reverse_rotate(a, 'a', moves);
    }
    else if (first > second && second < third && first > third)
        rotate(a, 'a', moves);
    else if (first < second && second > third && first < third)
    {
        swap(a, 'a', moves);
        rotate(a, 'a', moves);
    }
    else if (first < second && second > third && first > third)
        reverse_rotate(a, 'a', moves);
}

static void push_small_to_b(t_stack *a, t_stack *b, int max_push, t_moves *moves)
{
    int pushed = 0;
    int min;

    while (pushed < max_push)
    {
        min = get_min_value(a);
        printf("Pushing min %d to B\n", min);
        int moves_count = 0; // Renombrado para evitar conflicto con el puntero 'moves'
        while (a->first_node->value != min)
        {
            if (get_min_position(a) <= stack_size(a) / 2)
                rotate(a, 'a', moves);
            else
                reverse_rotate(a, 'a', moves);
            
            moves_count++;
            if (moves_count > stack_size(a)) // Evita bucle infinito
            {
                printf("Error: infinite loop detected in push_small_to_b!\n");
                return;
            }
        }
        push(a, b, 'b', moves); // Usar moves correctamente
        pushed++;
    }
}

void sort_five(t_stack *a, t_stack *b, t_moves *moves)
{
    int size;

    size = stack_size(a);
    if (size <= 3)
    {
        sort_three(a, moves);
        return;
    }
    push_small_to_b(a, b, 2, moves);      // Pasar 'moves' correctamente
    sort_three(a, moves);                 // Pasar 'moves' correctamente
    while (b->first_node)
        push(b, a, 'a', moves);           // Pasar 'moves' correctamente
}

static void sort_chunk(t_stack **a, t_stack **b, int min, int max, t_moves *moves)
{
    int initial_size = stack_size(*a);
    int rotated = 0;

    while (*a && (*a)->first_node && rotated < initial_size) // Evita bucle infinito
    {
        if ((*a)->first_node->value >= min && (*a)->first_node->value <= max)
        {
            printf("Pushing %d to B\n", (*a)->first_node->value);
            push(*a, *b, 'b', moves);       // Usar moves correctamente
            if ((*b)->first_node->value < (min + max) / 2)
                rotate(*b, 'b', moves);    // Usar moves correctamente
        }
        else
        {
            rotate(*a, 'a', moves);       // Usar moves correctamente
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

void big_sort(t_stack **a, t_stack **b, t_moves *moves)
{
    int size;
    int min;
    int max;
    int chunk_size;
    int i;

    size = stack_size(*a);
    if (size <= 5)
    {
        sort_five(*a, *b, moves);         // Pasar 'moves' correctamente
        return;
    }
    min = get_min_value(*a);
    max = get_max_value(*a);
    chunk_size = (max - min) / 4;
    i = 0;
    
    while (i < 4)
    {
        sort_chunk(a, b, min + (i * chunk_size), min + ((i + 1) * chunk_size), moves); // Usar moves correctamente
        i++;
    }

    while (*a && (*a)->first_node)
    {
        push(*a, *b, 'b', moves); // Usar moves correctamente
    }

    while (*b && (*b)->first_node)
    {
        max = get_max_value(*b);
        printf("Moving max %d from B to A\n", max);
        while ((*b)->first_node->value != max)
        {
            if (get_max_position(*b) <= stack_size(*b) / 2)
                rotate(*b, 'b', moves); // Usar moves correctamente
            else
                reverse_rotate(*b, 'b', moves); // Usar moves correctamente
        }
        push(*b, *a, 'a', moves); // Usar moves correctamente
    }
}
