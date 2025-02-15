#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_moves
{
    char **moves;
    int count;
} t_moves;

typedef struct s_node {
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node *first_node;
    int move_count;  // Se añadió el contador de movimientos
} t_stack;

// Funciones de validación
int     is_number(char *str);
int     check_duplicates(t_stack *stack);
long    ft_atol(const char *str);
void    free_stack(t_stack *stack);
int     is_sorted(t_stack *stack);
int     init_stack(t_stack **stack);

// Operaciones básicas
void    push(t_stack *src, t_stack *dest, char stack, t_moves *moves);
void    rotate(t_stack *stack, char stack_name, t_moves *moves);
void    reverse_rotate(t_stack *stack, char stack_name, t_moves *moves);
void    swap(t_stack *stack, char stack_name, t_moves *moves);
void    ss(t_stack *a, t_stack *b, t_moves *moves);
void    rr(t_stack *a, t_stack *b, t_moves *moves);
void    rrr(t_stack *a, t_stack *b, t_moves *moves);

// Funciones de ordenamiento
void    sort_three(t_stack *a, t_moves *moves);
void sort_five(t_stack *a, t_stack *b, t_moves *moves);
void big_sort(t_stack **a, t_stack **b, t_moves *moves);
int     stack_size(t_stack *stack);
int     get_min_position(t_stack *stack);
int     get_min_value(t_stack *stack);
int     get_max_value(t_stack *stack);
void print_moves(t_moves *moves);
int init_moves(t_moves *moves, int max_size);
void free_moves(t_moves *moves);

#endif