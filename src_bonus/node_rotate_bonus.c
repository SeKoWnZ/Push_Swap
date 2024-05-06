/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:22:08 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 13:28:39 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

t_node	*stacklast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	node_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = stacklast(*stack);
	last->next = tmp;
	tmp->next = NULL;
	return ;
}

void	ra(t_node **stack_a)
{
	node_rotate(stack_a);
}

void	rb(t_node **stack_b)
{
	node_rotate(stack_b);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	node_rotate(stack_a);
	node_rotate(stack_b);
}
