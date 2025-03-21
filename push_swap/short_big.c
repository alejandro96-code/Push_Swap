/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:34:02 by alejandro         #+#    #+#             */
/*   Updated: 2025/03/21 12:36:50 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_stack **a, t_stack **b, int min, int max)
{
	int	initial_size;
	int	rotated;

	initial_size = stack_size(*a);
	rotated = 0;
	while (*a && (*a)->first_node && rotated < initial_size)
	{
		if ((*a)->first_node->value >= min && (*a)->first_node->value <= max)
		{
			push(*a, *b, 'b');
			if ((*b)->first_node->value < (min + max) / 2)
				rotate(*b, 'b');
		}
		else
		{
			rotate(*a, 'a');
			rotated++;
		}
	}
}

void	split_into_chunks(t_stack **a, t_stack **b, int min, int max)
{
	int	chunk_size;
	int	cont;

	chunk_size = (max - min) / 4;
	cont = 0;
	while (cont < 4)
	{
		sort_chunk(a, b, min + (cont * chunk_size), min + ((cont + 1)
				* chunk_size));
		cont++;
	}
	while (*a && (*a)->first_node)
	{
		push(*a, *b, 'b');
	}
}

void	sort_b_stack(t_stack **a, t_stack **b)
{
	int	max;

	while (*b && (*b)->first_node)
	{
		max = get_max_value(*b);
		while ((*b)->first_node->value != max)
		{
			if (get_max_position(*b) <= stack_size(*b) / 2)
				rotate(*b, 'b');
			else
				reverse_rotate(*b, 'b');
		}
		push(*b, *a, 'a');
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	min;
	int	max;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_five(*a, *b);
		return ;
	}
	min = get_min_value(*a);
	max = get_max_value(*a);
	split_into_chunks(a, b, min, max);
	sort_b_stack(a, b);
}
