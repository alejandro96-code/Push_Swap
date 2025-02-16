#include "push_swap.h"

void ss(t_stack *a, t_stack *b)
{
    swap(a, 'x');
    swap(b, 'x');
    write(1, "ss\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a, 'x');
    rotate(b, 'x');
    write(1, "rr\n", 3);
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a, 'x');
    reverse_rotate(b, 'x');
    write(1, "rrr\n", 4);
}