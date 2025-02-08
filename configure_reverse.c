/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanr2 <alejanr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:30:03 by alejanr2          #+#    #+#             */
/*   Updated: 2025/02/08 08:51:24 by alejanr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"


int	rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	if (a->first_node == NULL || a->first_node->next == NULL)
		return;
	last = a->first_node;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = a->first_node;
	a->first_node = last;
	write(1, "rra\n", 5);
	return (0);
}

int	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*second_last;

	if (b->first_node == NULL || b->first_node->next == NULL)
		return;
	last = b->first_node;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = b->first_node;
	b->first_node = last;
	write(1, "rrb\n", 5);
	return (0);
}

int	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 5);
	return (0);
}

