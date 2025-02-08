/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanr2 <alejanr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:30:03 by alejanr2          #+#    #+#             */
/*   Updated: 2025/02/08 08:52:35 by alejanr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"


void	sa(t_stack *a)
{
	t_node	*temp2;
	t_node	*temp1;

	if (a->first_node == NULL || a->first_node->next == NULL)
		return;
	temp2 = a->first_node->next;
	temp1 = a->first_node;
	temp1->next = temp2->next;
	temp2->next = temp1;
	a->first_node = temp2;
	write(1, "sa\n", 4);
}

void	sb(t_stack *b)
{
	t_node	*temp2;
	t_node	*temp1;

	if (b->first_node == NULL || b->first_node->next == NULL)
		return;
	temp2 = b->first_node->next;
	temp1 = b->first_node;
	temp1->next = temp2->next;
	temp2->next = temp1;
	b->first_node = temp2;
	write(1, "sb\n", 4);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);  
	write(1, "ss\n", 4);
}
