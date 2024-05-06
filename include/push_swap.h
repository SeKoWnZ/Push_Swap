/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:56:28 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/06 11:45:26 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// stack creation:

t_node				*ft_notlast(t_node *lst);
t_node				*check_args(char ***splitted_list);
t_node				*create_stack(long int *current, int lng);
int					argsleng(char **args);
int					w_counter(char *str);
void				join_args(int argc, char **args, char **prelist);
void				split_args(char **prelist, char ***splitted_lst);
long				atoli(char *str);

// movements:

void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack);
void				rrb(t_node **stack);
void				rrr(t_node **stack_a, t_node **stack_b);

// algorithm:

void				set_nodes(t_node *stack, int size);
void				sort_three(t_node **stack_a);
void				set_targets(t_node *a, t_node *b);
void				cost_cal(t_node *b, int *cost, int sizeb, int sizea);
void				sortit(t_node **stack_a, t_node **stack_b);
void				end_status(t_node **stack_a);
void				make_move(t_node *tar, t_node **a, t_node **b);
void				reset_nodes(t_node *a, t_node *b);
t_node				*first_last_max(t_node *a);
t_node				*ft_find_min(t_node *a);
t_node				*set_cheapest(t_node *b, int sizeb, int sizea);
int					stack_size(t_node *stack);
int					sorted_ok(t_node *stack_a, t_node *stack_b);

// memory:

void				double_free(char **trash, int error);
void				free_stacks(t_node **a, t_node **b, int error);

#endif