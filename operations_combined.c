#include "push_swap.h"

void ss(t_stack *a, t_stack *b, t_moves *moves)
{
    swap(a, 'a', moves);  // Usamos 'a' para la pila 'a'
    swap(b, 'b', moves);  // Usamos 'b' para la pila 'b'
    moves->moves[moves->count] = "ss";  // Almacenar la operación
    moves->count++;  // Incrementar el contador
    write(1, "ss\n", 3);
}

void rr(t_stack *a, t_stack *b, t_moves *moves)
{
    rotate(a, 'a', moves);  // Usamos 'a' para la pila 'a'
    rotate(b, 'b', moves);  // Usamos 'b' para la pila 'b'
    moves->moves[moves->count] = "rr";  // Almacenar la operación
    moves->count++;  // Incrementar el contador
    write(1, "rr\n", 3);
}

void rrr(t_stack *a, t_stack *b, t_moves *moves)
{
    reverse_rotate(a, 'a', moves);  // Usamos 'a' para la pila 'a'
    reverse_rotate(b, 'b', moves);  // Usamos 'b' para la pila 'b'
    moves->moves[moves->count] = "rrr";  // Alma
    moves->count++;  // Incrementar el contador
    write(1, "rrr\n", 4);
}