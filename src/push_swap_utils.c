/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:07 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 17:42:42 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (size);
	while (stack)
	{
		stack->pos = ++size;
		stack = stack->next;
	}
	return (size);
}

void	set_nodes(t_node *stack, int size)
{
	int	not;

	not = 1;
	stack->first = 1;
	stack = stack->next;
	if (!stack)
		return ;
	else
	{
		while (stack->next)
		{
			if (stack->pos > size / 2)
			{
				if (not && (size % 2))
					not --;
				else
					stack->mid = 1;
			}
			stack = stack->next;
		}
	}
	stack->last = 1;
	stack->mid = 1;
}

t_node	*first_last_max(t_node *a)
{
	t_node	*max;

	max = a;
	a->first = 1;
	a->last = 0;
	a = a->next;
	if (!a)
	{
		max->last = 1;
		return (max);
	}
	while (a->next)
	{
		if (a->value > max->value)
			max = a;
		a->first = 0;
		a->last = 0;
		a = a->next;
	}
	if (a->value > max->value)
		max = a;
	a->last = 1;
	a->first = 0;
	return (max);
}

void	reset_nodes(t_node *a, t_node *b)
{
	while (a)
	{
		a->first = 0;
		a->last = 0;
		a->mid = 0;
		a->min = 0;
		a->pos = 0;
		a->target = NULL;
		a = a->next;
	}
	while (b)
	{
		b->first = 0;
		b->last = 0;
		b->mid = 0;
		b->min = 0;
		b->pos = 0;
		b->target = NULL;
		b = b->next;
	}
}

t_node	*ft_find_min(t_node *a)
{
	int		pos;
	t_node	*min;

	min = a;
	pos = 1;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a->pos = pos++;
		a = a->next;
	}
	return (min);
}
