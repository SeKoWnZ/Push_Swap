/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:53:54 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/16 12:34:23 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	node_swap(t_node **stack)
{
	t_node	*tmp;

	if (*stack == NULL || stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_node **stack_a)
{
	node_swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	node_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	node_swap(stack_a);
	node_swap(stack_b);
	write(1, "ss\n", 3);
}
