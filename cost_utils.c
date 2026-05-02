/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:05:00 by aleja             #+#    #+#             */
/*   Updated: 2026/05/02 17:24:28 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	abs_int(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

static int	get_total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = abs_int(cost_a);
	abs_b = abs_int(cost_b);
	if (cost_a * cost_b > 0)
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

static void	try_cost(t_cost_ctx *ctx, t_node *current, int pos_b)
{
	int	target_pos;
	int	cost_a;
	int	cost_b;
	int	total;

	target_pos = get_target_position(ctx->a, current->index);
	cost_a = get_cost(target_pos, stack_size(ctx->a));
	cost_b = get_cost(pos_b, stack_size(ctx->b));
	total = get_total_cost(cost_a, cost_b);
	if (total < *(ctx->best_total))
	{
		*(ctx->best_total) = total;
		*(ctx->best_a) = cost_a;
		*(ctx->best_b) = cost_b;
	}
}

void	get_cheapest_costs(t_stack *a, t_stack *b, int *best_a, int *best_b)
{
	int			pos_b;
	int			best_total;
	t_node		*current;
	t_cost_ctx	ctx;

	best_total = INT_MAX;
	ctx.a = a;
	ctx.b = b;
	ctx.best_total = &best_total;
	ctx.best_a = best_a;
	ctx.best_b = best_b;
	pos_b = 0;
	current = b->first_node;
	while (current)
	{
		try_cost(&ctx, current, pos_b);
		pos_b++;
		current = current->next;
	}
}
