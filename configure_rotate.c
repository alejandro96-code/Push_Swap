/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanr2 <alejanr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:30:03 by alejanr2          #+#    #+#             */
/*   Updated: 2025/02/08 08:51:46 by alejanr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"


void	ra(t_stack *a)
{
	t_node	*temp;
	t_node	*last;

	if (a->first_node == NULL || a->first_node->next == NULL)
		return;
	temp = a->first_node;
	a->first_node = a->first_node->next;
	temp->next = NULL;
	last = a->first_node;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "ra\n", 4);
}

void	rb(t_stack *b)
{
	t_node	*temp;
	t_node	*last;

	if (b->first_node == NULL || b->first_node->next == NULL)
		return;
	temp = b->first_node;
	b->first_node = b->first_node->next;
	temp->next = NULL;
	last = b->first_node;
	while (last->next)
		last = last->next;
	last->next = temp;
	write(1, "rb\n", 4);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 4);
}
