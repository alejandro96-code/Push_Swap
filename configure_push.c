/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanr2 <alejanr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:30:03 by alejanr2          #+#    #+#             */
/*   Updated: 2025/02/08 08:51:02 by alejanr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	pa(t_stack *a, t_stack *b)
{
	t_node *temp;

	if (b->first_node == NULL)
		return;
	temp = b->first_node;
	b->first_node = b->first_node->next;
	temp->next = a->first_node;
	a->first_node = temp;
	write(1, "pa\n", 4);
	return (0);
}

int	pb(t_stack *a, t_stack *b)
{
	t_node *temp;
	
	if (a->first_node == NULL)
		return;
	temp = a->first_node;
	a->first_node = a->first_node->next;
	temp->next = b->first_node;
	b->first_node = temp;
	write(1, "pb\n", 4);
	return (0);
}

