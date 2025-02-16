#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack {
    t_node  *first_node;
} t_stack;

// check_utils.c
int is_number(char *str);
int check_duplicates(t_stack *stack);
int is_sorted(t_stack *stack);

//stack_utils.c
int stack_size(t_stack *stack);
int init_stack(t_stack **stack);
int add_number(t_stack *stack, char *str);
int process_arguments(int argc, char **argv, t_stack *a);

//stack_values.c
int get_min_value(t_stack *stack);
int get_max_value(t_stack *stack);
int get_min_position(t_stack *stack);
int get_max_position(t_stack *stack);

//basic_operations.c
void swap(t_stack *stack, char stack_name);
void push(t_stack *src, t_stack *dest, char stack);
void rotate(t_stack *stack, char stack_name);
t_node *get_last_and_second_last(t_stack *stack, t_node **second_last);
void reverse_rotate(t_stack *stack, char stack_name);

//combined_operations.c
void ss(t_stack *a, t_stack *b);
void rr(t_stack *a, t_stack *b);
void rrr(t_stack *a, t_stack *b);

//sort_small.c
void sort_three(t_stack *a);
void sort_five(t_stack *a, t_stack *b);
void push_small_to_b(t_stack *a, t_stack *b, int max_push);

// sort_big.c
void sort_chunk(t_stack **a, t_stack **b, int min, int max);
void split_into_chunks(t_stack **a, t_stack **b, int min, int max);
void sort_b_stack(t_stack **a, t_stack **b);
void big_sort(t_stack **a, t_stack **b);

// memory.c
void free_stack(t_stack *stack);
long ft_atol(const char *str);

//main.c
int main(int argc, char **argv);
#endif