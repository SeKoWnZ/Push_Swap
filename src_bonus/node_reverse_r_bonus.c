/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_reverse_r_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:56:13 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 17:26:00 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

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

	if (!(*stack) || !(*stack)->next)
		return ;
	notlast = ft_notlast(*stack);
	tmp = notlast->next;
	notlast->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_node **stack)
{
	node_reverse_r(stack);
}

void	rrb(t_node **stack)
{
	node_reverse_r(stack);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	node_reverse_r(stack_a);
	node_reverse_r(stack_b);
}
