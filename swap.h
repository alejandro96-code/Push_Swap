/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejanr2 <alejanr2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:30:03 by alejanr2          #+#    #+#             */
/*   Updated: 2025/02/08 08:41:28 by alejanr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Librerias
# include <unistd.h>
# include <stdlib.h>

//estructura de cada nodo
typedef struct s_node
{
	struct s_node	*next;
}	t_node;


//Estructura del stack
typedef struct s_stack
{
	//...
	t_node	*first_node;
}	t_stack;


//funciones
int	main(int ac, char **av);

#endif