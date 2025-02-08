#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

// Funciones de operaciones
void push(t_stack **a, t_stack **b, char stack);
void swap(t_stack *stack, char stack_name);
void rotate(t_stack **stack, char stack_name);
void reverse_rotate(t_stack **stack, char stack_name);

// Funciones de sorting
void push_swap(t_stack **a, t_stack **b);
void big_sort(t_stack **a, t_stack **b);
void insert_sorted_back(t_stack **a, t_stack **b, int *sorted_array);
int find_best_move(t_stack *a, t_stack *b, int *sorted_array);
void execute_best_move(t_stack **a, t_stack **b, int best_move);

// Funciones auxiliares
void stack_push(t_stack **stack, int value);
int stack_size(t_stack *stack);
int *stack_to_sorted_array(t_stack *stack);

#endif
