/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:34:16 by alejandro         #+#    #+#             */
/*   Updated: 2025/03/21 12:35:28 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack->first_node;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return (0);
	(*stack)->first_node = NULL;
	return (1);
}

int	add_number(t_stack *stack, char *str)
{
	long	num;
	t_node	*new_node;
	t_node	*temp;

	if (!is_number(str))
		return (0);
	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483647)
		return (0);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = (int)num;
	new_node->next = NULL;
	if (!stack->first_node)
		stack->first_node = new_node;
	else
	{
		temp = stack->first_node;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	return (1);
}

int	process_arguments(int argc, char **argv, t_stack *a)
{
	int	cont;

	cont = 1;
	while (cont < argc)
	{
		if (!process_single_argument(argv[cont], a))
			return (0);
		cont++;
	}
	if (check_duplicates(a))
		return (0);
	return (1);
}
