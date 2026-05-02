/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:05:00 by aleja             #+#    #+#             */
/*   Updated: 2026/05/02 19:06:57 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk;
	int	cont;

	size = stack_size(*a);
	chunk = 30;
	if (size <= 100)
		chunk = 15;
	cont = 0;
	while (stack_size(*a) > 3)
	{
		if ((*a)->first_node->index <= cont)
		{
			push(*a, *b, 'b');
			rotate(*b, 'b');
			cont++;
		}
		else if ((*a)->first_node->index <= cont + chunk)
		{
			push(*a, *b, 'b');
			cont++;
		}
		else
			rotate(*a, 'a');
	}
}
