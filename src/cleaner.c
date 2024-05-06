/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:48:51 by jose-gon          #+#    #+#             */
/*   Updated: 2024/03/14 19:58:54 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	double_free(char **trash, int error)
{
	int	i;

	i = -1;
	while (trash[++i])
		free(trash[i]);
	free(trash);
	if (error)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	free_stacks(t_node **a, t_node **b, int error)
{
	t_node	*tmp;

	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
	}
	if (b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free(*b);
			*b = tmp;
		}
	}
	if (error)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
