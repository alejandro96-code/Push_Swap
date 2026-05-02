/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleja <aleja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:32:02 by alejandro         #+#    #+#             */
/*   Updated: 2026/05/02 17:19:52 by aleja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cleanup_and_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
}

static int	init_and_check(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc < 2)
		return (0);
	if (!init_stack(a) || !init_stack(b) || !process_arguments(argc, argv, *a))
	{
		cleanup_and_error(*a, *b);
		return (-1);
	}
	if (is_sorted(*a))
	{
		free_stack(*a);
		free_stack(*b);
		return (0);
	}
	return (1);
}

static void	run_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		big_sort(&a, &b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		status;

	status = init_and_check(argc, argv, &a, &b);
	if (status <= 0)
		return (status < 0);
	run_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
