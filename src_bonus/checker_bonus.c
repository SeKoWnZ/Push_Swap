/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:56:20 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/19 17:46:17 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

void	check_inputs(char *line, t_node **a, t_node **b)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else
		free_all(line, a, b);
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

void	write_result(t_node *stack_a, t_node *stack_b)
{
	if (sorted_ok(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;

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
	line = get_next_line(0);
	while (line)
	{
		check_inputs(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	write_result(stack_a, stack_b);
	free(line);
	free_stacks(&stack_a, &stack_b, OK);
}
