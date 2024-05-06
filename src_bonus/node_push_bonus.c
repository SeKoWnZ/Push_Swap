/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:53:36 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 17:16:22 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

void	node_push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	node_push(stack_b, stack_a);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	node_push(stack_a, stack_b);
}
