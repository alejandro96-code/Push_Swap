/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:05:00 by aleja             #+#    #+#             */
/*   Updated: 2026/05/02 17:24:31 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_a(t_stack *a, int *cost_a)
{
	while (*cost_a > 0)
	{
		rotate(a, 'a');
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		reverse_rotate(a, 'a');
		(*cost_a)++;
	}
}

static void	rotate_b(t_stack *b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rotate(b, 'b');
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		reverse_rotate(b, 'b');
		(*cost_b)++;
	}
}

void	apply_rotations(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	rotate_both(a, b, cost_a, cost_b);
	rotate_a(a, cost_a);
	rotate_b(b, cost_b);
}

void	final_rotate(t_stack *a)
{
	int	pos;
	int	cost;

	pos = get_position(a, get_min_index(a));
	cost = get_cost(pos, stack_size(a));
	while (cost > 0)
	{
		rotate(a, 'a');
		cost--;
	}
	while (cost < 0)
	{
		reverse_rotate(a, 'a');
		cost++;
	}
}
