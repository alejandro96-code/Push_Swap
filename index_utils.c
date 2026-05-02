/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:05:00 by aleja             #+#    #+#             */
/*   Updated: 2026/05/02 17:19:52 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *a, int size)
{
	int		*arr;
	int		i;
	t_node	*current;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = a->first_node;
	i = 0;
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	return (arr);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

int	assign_indices(t_stack *a)
{
	int		*arr;
	int		size;
	t_node	*current;

	size = stack_size(a);
	arr = stack_to_array(a, size);
	if (!arr)
		return (0);
	sort_array(arr, size);
	current = a->first_node;
	while (current)
	{
		current->index = find_index(arr, size, current->value);
		current = current->next;
	}
	free(arr);
	return (1);
}
