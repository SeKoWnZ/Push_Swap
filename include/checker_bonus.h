/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:08:42 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/06 11:45:20 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				pos;
	int				min;
	int				mid;
	int				first;
	int				last;
	struct s_node	*target;
	struct s_node	*next;
}					t_node;

typedef enum e_error
{
	OK,
	ERROR
}					t_error;

// movements

void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack);
void				rrb(t_node **stack);
void				rrr(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);

void				join_args(int argc, char **args, char **prelist);
void				split_args(char **prelist, char ***splitted_lst);
t_node				*check_args(char ***splitted_list);
t_node				*create_stack(long int *current, int lng);

char				*get_next_line(int fd);

void				double_free(char **trash, int error);
void				free_all(char *line, t_node **a, t_node **b);
void				free_stacks(t_node **a, t_node **b, int error);

#endif