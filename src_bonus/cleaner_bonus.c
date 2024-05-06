/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:07:17 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 16:02:41 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

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

void	free_all(char *line, t_node **a, t_node **b)
{
	free(line);
	free_stacks(a, b, ERROR);
}
