/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:47:26 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/16 12:34:23 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	argsleng(char **args)
{
	int	leng;
	int	i;

	leng = 0;
	while (*++args)
	{
		i = 0;
		while (*(*args + i++))
			leng++;
	}
	return (leng);
}

void	join_args(int argc, char **args, char **prelist)
{
	int	i;
	int	j;

	j = 0;
	*prelist = (char *)malloc(sizeof(char) * (argsleng(args) + argc));
	if (!*prelist)
		return ;
	while (*++args)
	{
		i = 0;
		while (*(*args + i))
			*(*prelist + j++) = *(*args + i++);
		*(*prelist + j++) = ' ';
	}
	*(*prelist + j) = '\0';
	return ;
}
