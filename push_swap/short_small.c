/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanr2 <alejanr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:11:28 by alejanr2          #+#    #+#             */
/*   Updated: 2025/02/19 18:11:29 by alejanr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_small_to_b(t_stack *a, t_stack *b, int max_push)
{
	int	pushed;
	int	min;
	int	stack_len;

	pushed = 0;
	stack_len = stack_size(a);
	while (pushed < max_push && stack_len > 0)
	{
		min = get_min_value(a);
		if (a->first_node->value == min)
		{
			push(a, b, 'b');
			pushed++;
		}
		else if (get_min_position(a) <= stack_len / 2)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
		stack_len = stack_size(a);
	}
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a->first_node || !a->first_node->next || !a->first_node->next->next)
		return ;
	first = a->first_node->value;
	second = a->first_node->next->value;
	third = a->first_node->next->next->value;
	if (first > second && second < third && first < third)
		swap(a, 'a');
	else if (first > second && second > third)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (first > second && second < third && first > third)
		rotate(a, 'a');
	else if (first < second && second > third && first < third)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a, 'a');
}

void	sort_five(t_stack *a, t_stack *b)
{
	int size;

	size = stack_size(a);
	if (size <= 3)
	{
		sort_three(a);
		return ;
	}
	push_small_to_b(a, b, size - 3);
	sort_three(a);
	while (b->first_node)
		push(b, a, 'a');
}