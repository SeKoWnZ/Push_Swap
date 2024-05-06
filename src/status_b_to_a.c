/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_b_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:18:54 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/20 13:58:35 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_targets(t_node *a, t_node *b)
{
	t_node	*tmpa;

	while (b)
	{
		tmpa = a;
		while (tmpa)
		{
			if (tmpa->value > b->value)
			{
				if (b->target == NULL)
					b->target = tmpa;
				if (tmpa->value < b->target->value)
					b->target = tmpa;
			}
			tmpa = tmpa->next;
		}
		b = b->next;
	}
}

void	cost_cal(t_node *b, int *cost, int sizeb, int sizea)
{
	if (b->mid)
		*cost += sizeb - b->pos + 1;
	else
		*cost += b->pos - 1;
	if (b->target->mid)
		*cost += sizea - b->target->pos + 1;
	else
		*cost += b->target->pos - 1;
	if (b->mid && b->target->mid)
	{
		if ((sizeb - b->pos + 1) < (sizea - b->target->pos + 1))
			*cost -= sizeb - b->pos + 1;
		else
			*cost -= sizea - b->target->pos + 1;
	}
	if (!b->mid && !b->target->mid)
	{
		if ((b->pos - 1) < (b->target->pos - 1))
			*cost -= b->pos - 1;
		else
			*cost -= b->target->pos - 1;
	}
}

t_node	*set_cheapest(t_node *b, int sizeb, int sizea)
{
	t_node	*cheap;
	int		cost;
	int		best;

	cheap = NULL;
	cost = 0;
	best = 0;
	while (b)
	{
		cost_cal(b, &cost, sizeb, sizea);
		if (cost < best || best == 0)
		{
			best = cost;
			cheap = b;
		}
		cost = 0;
		b = b->next;
	}
	return (cheap);
}
