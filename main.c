#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return 0;
    // Parsing y llenado de la pila 'a' aquí
    push_swap(&a, &b);
    return 0;
}
