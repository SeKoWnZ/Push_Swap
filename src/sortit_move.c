/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortit_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:26:57 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/16 12:34:23 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	belowmid(t_node *tar, t_node **a, t_node **b)
{
	if ((!tar->last && !tar->target->last) || (tar->last && tar->target->last))
	{
		rrr(a, b);
		return ;
	}
	if (!tar->last)
		rrb(b);
	if (!tar->target->last)
		rra(a);
}

void	abovemid(t_node *tar, t_node **a, t_node **b)
{
	if (!tar->first && !tar->target->first)
	{
		rr(a, b);
		return ;
	}
	if (!tar->first)
		rb(b);
	if (!tar->target->first)
		ra(a);
}

void	make_move(t_node *tar, t_node **a, t_node **b)
{
	if (!tar->mid && !tar->target->mid)
	{
		abovemid(tar, a, b);
		return ;
	}
	if (tar->mid && tar->target->mid)
	{
		belowmid(tar, a, b);
		return ;
	}
	if (!tar->first)
	{
		if (!tar->mid)
			rb(b);
		else
			rrb(b);
	}
	if (!tar->target->first)
	{
		if (!tar->target->mid)
			ra(a);
		else
			rra(a);
	}
}
