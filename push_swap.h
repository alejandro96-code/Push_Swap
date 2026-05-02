/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:17:43 by alejandro         #+#    #+#             */
/*   Updated: 2026/05/02 17:57:26 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*first_node;
}	t_stack;

typedef struct s_cost_ctx
{
	t_stack			*a;
	t_stack			*b;
	int				*best_total;
	int				*best_a;
	int				*best_b;
}	t_cost_ctx;

// check_utils.c
int		is_number(char *str);
int		check_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);

// stack_utils.c
int		stack_size(t_stack *stack);
int		init_stack(t_stack **stack);
int		add_number(t_stack *stack, char *str);
int		process_arguments(int argc, char **argv, t_stack *a);

// stack_values.c
int		get_min_value(t_stack *stack);
int		get_min_position(t_stack *stack);

// basic_operations.c
void	swap(t_stack *stack, char stack_name);
void	push(t_stack *src, t_stack *dest, char stack);
void	rotate(t_stack *stack, char stack_name);
t_node	*get_last_and_second_last(t_stack *stack, t_node **second_last);
void	reverse_rotate(t_stack *stack, char stack_name);

// combined_operations.c
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// sort_small.c
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	push_small_to_b(t_stack *a, t_stack *b, int max_push);

// sort_big.c
void	big_sort(t_stack **a, t_stack **b);

// index_utils.c
int		assign_indices(t_stack *a);

// position_utils.c
int		get_position(t_stack *stack, int index);
int		get_min_index(t_stack *stack);
int		get_max_index(t_stack *stack);
int		get_target_position(t_stack *a, int b_index);

// cost_utils.c
int		get_cost(int pos, int size);
void	get_cheapest_costs(t_stack *a, t_stack *b, int *best_a, int *best_b);

// rotation_utils.c
void	apply_rotations(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	final_rotate(t_stack *a);

// push_utils.c
void	push_to_b(t_stack **a, t_stack **b);

// memory.c
void	free_stack(t_stack *stack);
long	ft_atol(const char *str);

// split_utils.c
int		is_space(char c);
int		process_number(char *arg, t_stack *stack, int *i, int start);
int		process_single_argument(char *arg, t_stack *stack);

// main.c
int		main(int argc, char **argv);

#endif
