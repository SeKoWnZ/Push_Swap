/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:07:36 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 13:28:48 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	if (ft_strlen(s) <= start)
		l = 0;
	else
		l = (ft_strlen(s) - start);
	if (l > len)
		l = len;
	sub = malloc(l + 1);
	if (!sub || !s)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	w_counter(char *str)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			i++;
			words++;
		}
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (words);
}

void	split_args(char **prelist, char ***splitted_lst)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	*splitted_lst = (char **)malloc(sizeof(char *) * (w_counter(*prelist) + 1));
	if (!*splitted_lst || !*prelist)
		return ;
	while (prelist[0][i])
	{
		while (prelist[0][i] == ' ')
			i++;
		j = i;
		while (prelist[0][i] && prelist[0][i] != ' ')
			i++;
		if (i > j)
		{
			splitted_lst[0][k] = ft_substr(*prelist, j, i - j);
			if (!splitted_lst[0][k++])
				double_free(*splitted_lst, ERROR);
		}
	}
	free(*prelist);
	splitted_lst[0][k] = NULL;
}
