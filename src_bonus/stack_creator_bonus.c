/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:30:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 13:28:53 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

t_node	*node_last(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*new_node(long int content, int n)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = (int)content;
	new->pos = n;
	new->min = 0;
	new->mid = 0;
	new->first = 0;
	new->last = 0;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

void	node_add_back(t_node **lst, t_node *new)
{
	if (!new)
		free_stacks(lst, NULL, 1);
	if (!*lst)
		*lst = new;
	else
		node_last(*lst)->next = new;
}

t_node	*create_stack(long int *current, int lng)
{
	t_node	*stack_a;
	int		i;

	i = -1;
	stack_a = NULL;
	while (++i < lng)
	{
		node_add_back(&stack_a, new_node(current[i], i));
	}
	free(current);
	return (stack_a);
}
