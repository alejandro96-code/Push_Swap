/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:05:00 by aleja             #+#    #+#             */
/*   Updated: 2026/05/02 17:19:52 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	get_position(t_stack *stack, int index)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack->first_node;
	while (current)
	{
		if (current->index == index)
			return (pos);
		pos++;
		current = current->next;
	}
	return (0);
}

int	get_min_index(t_stack *stack)
{
	int		min;
	t_node	*current;

	current = stack->first_node;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	get_max_index(t_stack *stack)
{
	int		max;
	t_node	*current;

	current = stack->first_node;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

static int	find_best_position(t_stack *a, int b_index)
{
	int		best_index;
	int		best_pos;
	int		pos;
	t_node	*current;

	best_index = INT_MAX;
	best_pos = 0;
	pos = 0;
	current = a->first_node;
	while (current)
	{
		if (current->index > b_index && current->index < best_index)
		{
			best_index = current->index;
			best_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (best_pos);
}

int	get_target_position(t_stack *a, int b_index)
{
	int	min_index;
	int	max_index;

	min_index = get_min_index(a);
	max_index = get_max_index(a);
	if (b_index < min_index || b_index > max_index)
		return (get_position(a, min_index));
	return (find_best_position(a, b_index));
}
