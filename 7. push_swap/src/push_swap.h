/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/29 13:00:10 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef enum e_rotation
{
	AUBU = 0,
	ADBD = 1,
	AUBD = 2,
	ADBU = 3
}	t_rotation;

typedef struct s_nodes
{
	long			num;
	int				pos;
	struct s_nodes	*next;
	struct s_nodes	*prev;
	int				cost;
	int				cost_a;
	int				cost_b;
	int				target;
	t_rotation		rotation;
}	t_nodes;

typedef struct s_stack
{
	t_nodes	*stack_a;
	t_nodes	*stack_b;
	int		count;
	int		len_a;
	int		len_b;
}	t_stack;

typedef enum e_ab
{
	A = 0,
	B = 1
}	t_ab;

void	frees(t_stack *stack);
bool	sorted(t_nodes *stack_a);
t_stack	*main_check(int argc, char **argv, t_stack *stack);

bool	check_num_args(int argc, char **argv);
bool	only_nums(char **args);
bool	rep_nums(t_nodes *stack_a);

char	**split_args(int argc, char **argv, t_stack *stack);
t_nodes	*init_node(long num);
void	free_split(char **arg_split);
bool	node_loop(int argc, t_stack *stack, char **arg_split, int i);
bool	args2array(int argc, char **argv, t_stack *stack);

long	normal_search(t_stack *stack, long prev);
void	normal(t_stack *stack);

void	swap(t_nodes *stack_x);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	rotate(t_nodes *stack_x);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	reverse(t_nodes *stack_x);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	three(t_stack *stack);
void	five(t_stack *stack);

void	random2pos(t_stack *stack);
void	zero_first(t_stack *stack);
void	cost_algorithm(t_stack *stack);

void	calculate_pos(t_nodes *stack_x);
int		find_next(t_nodes *stack_a, long num);
void	targets(t_stack *stack);
int		ft_abs(int n);
int		min_cost(t_stack *stack);

void	same_dir(t_nodes *stack_b, int cost_a, int cost_b);
void	diff_dir2(t_stack *stack, t_nodes *stack_b, int cost_a, int cost_b);
void	diff_dir1(t_stack *stack, t_nodes *stack_b, int cost_a, int cost_b);
void	total_cost(t_stack *stack, t_nodes *stack_b, int cost_a, int cost_b);
void	costs(t_stack *stack);

void	aubu(t_stack *stack, int target, int pos_cost);
void	adbd(t_stack *stack, int target, int pos_cost);
void	aubd(t_stack *stack, int target, int pos_cost);
void	adbu(t_stack *stack, int target, int pos_cost);
void	moving(t_stack *stack, int pos_cost);

#endif