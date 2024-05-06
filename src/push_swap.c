/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:56:02 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 13:27:16 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sorted_ok(t_node *stack_a, t_node *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_three(t_node **stack_a)
{
	t_node	*highest;

	highest = first_last_max(*stack_a);
	if (*stack_a == highest)
		ra(stack_a);
	else if ((*stack_a)->next == highest)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	stack_maker(t_node **stack_a, int argc, char **args)
{
	char	*prelist;
	char	**splitted_list;

	prelist = NULL;
	splitted_list = NULL;
	join_args(argc, args, &prelist);
	split_args(&prelist, &splitted_list);
	*stack_a = check_args(&splitted_list);
	double_free(splitted_list, OK);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_maker(&stack_a, argc, argv);
	if (!sorted_ok(stack_a, stack_b))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a);
		if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sortit(&stack_a, &stack_b);
	}
	free_stacks(&stack_a, &stack_b, 0);
	return (0);
}
