/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_reverse_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:56:13 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/16 12:34:23 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*ft_notlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	node_reverse_r(t_node **stack)
{
	t_node	*notlast;
	t_node	*tmp;

	notlast = ft_notlast(*stack);
	tmp = notlast->next;
	notlast->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_node **stack)
{
	node_reverse_r(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack)
{
	node_reverse_r(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	node_reverse_r(stack_a);
	node_reverse_r(stack_b);
	write(1, "rrr\n", 4);
}
