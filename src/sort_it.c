/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:03:50 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/16 13:36:48 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	mean_val(t_node *a, int size)
{
	long	mean;

	mean = 0;
	while (a)
	{
		mean += (long)a->value;
		a = a->next;
	}
	mean = mean / (long)size;
	return ((int)mean);
}

void	push_mean(t_node **stack_a, t_node **stack_b, int mean)
{
	if ((*stack_a)->value < mean)
		pb(stack_a, stack_b);
	else
		ra(stack_a);
}

void	make_movements(t_node *tar, t_node **a, t_node **b)
{
	while (!tar->first || !tar->target->first)
	{
		make_move(tar, a, b);
		first_last_max(*a);
		first_last_max(*b);
	}
	pa(a, b);
	reset_nodes(*a, *b);
}

void	end_status(t_node **stack_a)
{
	int		sizea;
	t_node	*min;

	sizea = stack_size(*stack_a);
	set_nodes(*stack_a, sizea);
	min = ft_find_min(*stack_a);
	while ((*stack_a)->value != min->value)
	{
		if (min->mid)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	sortit(t_node **stack_a, t_node **stack_b)
{
	t_node	*tar;
	int		sizea;
	int		sizeb;

	while (stack_size(*stack_a) > 3)
		push_mean(stack_a, stack_b, mean_val(*stack_a, stack_size(*stack_a)));
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		sizea = stack_size(*stack_a);
		sizeb = stack_size(*stack_b);
		set_nodes(*stack_a, sizea);
		set_nodes(*stack_b, sizeb);
		set_targets(*stack_a, *stack_b);
		tar = set_cheapest(*stack_b, sizeb, sizea);
		make_movements(tar, stack_a, stack_b);
	}
	end_status(stack_a);
}
