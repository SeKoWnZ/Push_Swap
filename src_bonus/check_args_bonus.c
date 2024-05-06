/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:42:40 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 13:24:24 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

int	n_entries(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	atoli(char *str)
{
	long	final;
	int		i;
	long	negative;

	i = 0;
	negative = 1;
	final = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = (str[i] - '0') + (final * 10);
		i++;
	}
	return (final * negative);
}

int	no_twins(char **slist, long **current)
{
	int	i;
	int	j;

	i = 0;
	*current = (long *)malloc(sizeof(long) * n_entries(slist));
	if (!*current)
		return (0);
	while (slist[i])
	{
		*(*current + i) = atoli(slist[i]);
		if (*(*current + i) > INT_MAX || *(*current + i) < INT_MIN)
			return (0);
		j = -1;
		while (++j < i)
			if (*(*current + i) == *(*current + j))
				return (0);
		i++;
	}
	return (i);
}

int	allnums(char **slist)
{
	int	i;
	int	j;

	j = -1;
	while (slist[++j])
	{
		i = -1;
		if (!ft_isdigit(slist[j][++i]) && slist[j][0] != '+'
			&& slist[j][0] != '-')
			return (0);
		if ((slist[j][0] == '+' || slist[j][0] == '-') && !slist[j][1])
			return (0);
		while (slist[j][++i])
			if (!ft_isdigit(slist[j][i]))
				return (0);
	}
	return (1);
}

t_node	*check_args(char ***splitted_list)
{
	long int	*current;
	int			lng;

	if (!allnums(*splitted_list))
		double_free(*splitted_list, ERROR);
	lng = no_twins(*splitted_list, &current);
	if (!lng)
	{
		free(current);
		double_free(*splitted_list, ERROR);
	}
	return (create_stack(current, lng));
}
