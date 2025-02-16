#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);   
    if (!init_stack(&a) || !init_stack(&b) || \
        !process_arguments(argc, argv, a) || is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        write(2, "Error en los argumentos\n", 24);
        return (1);
    }
    if (stack_size(a) == 2)
        swap(a, 'a');
    else if (stack_size(a) == 3)
        sort_three(a);
    else if (stack_size(a) <= 5)
        sort_five(a, b);
    else
        big_sort(&a, &b);
    free_stack(a);
    free_stack(b);
    return (0);
}
