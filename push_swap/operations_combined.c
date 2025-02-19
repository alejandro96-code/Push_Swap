/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_combined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanr2 <alejanr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:11:19 by alejanr2          #+#    #+#             */
/*   Updated: 2025/02/19 18:11:19 by alejanr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a, 'x');
	swap(b, 'x');
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 'x');
	reverse_rotate(b, 'x');
	write(1, "rrr\n", 4);
}