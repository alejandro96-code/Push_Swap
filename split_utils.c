/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:34:11 by alejandro         #+#    #+#             */
/*   Updated: 2025/03/21 13:30:51 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	process_number(char *arg, t_stack *stack, int *i, int start)
{
	char	temp;

	if (arg[*i])
		temp = arg[*i];
	else
		temp = '\0';
	if (arg[*i])
		arg[*i] = '\0';
	if (!add_number(stack, &arg[start]))
	{
		if (temp)
			arg[*i] = temp;
		return (0);
	}
	if (temp)
		arg[*i] = temp;
	return (1);
}

int	process_single_argument(char *arg, t_stack *stack)
{
	int	i;
	int	start;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && is_space(arg[i]))
			i++;
		if (!arg[i])
			break ;
		start = i;
		while (arg[i] && !is_space(arg[i]))
			i++;
		if (!process_number(arg, stack, &i, start))
			return (0);
	}
	return (1);
}
