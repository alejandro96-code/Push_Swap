/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:05:00 by aleja             #+#    #+#             */
/*   Updated: 2026/05/02 17:19:52 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	cost_a;
	int	cost_b;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_five(*a, *b);
		return ;
	}
	if (!assign_indices(*a))
		return ;
	push_to_b(a, b);
	sort_three(*a);
	while ((*b)->first_node)
	{
		cost_a = 0;
		cost_b = 0;
		get_cheapest_costs(*a, *b, &cost_a, &cost_b);
		apply_rotations(*a, *b, &cost_a, &cost_b);
		push(*b, *a, 'a');
	}
	final_rotate(*a);
}
