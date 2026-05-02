/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:22:55 by alejandro         #+#    #+#             */
/*   Updated: 2025/03/21 12:35:21 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	cont;

	cont = 0;
	if (str[cont] == '-' || str[cont] == '+')
		cont++;
	if (!str[cont])
		return (0);
	while (str[cont])
	{
		if (str[cont] < '0' || str[cont] > '9')
			return (0);
		cont++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->first_node;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->first_node)
		return (1);
	current = stack->first_node;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
