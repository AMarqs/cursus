/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 16:45:23 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h> // Flags EXIT_SUCCESS and EXIT_FAILURE
# include <unistd.h> // write
# include <stdio.h> // printf----------------------------------BORRAR?
# include <stdbool.h> // bool
# include <limits.h> // INT_MAX

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

bool	sorted(t_nodes *stack);
void	frees(t_stack *t_stack);
void	main_check(t_stack *t_stack, int argc, char **argv);

bool	check_num_args(int argc);
bool	only_nums(char **args);
bool	rep_nums(t_nodes *stack);

char	**split_args(int argc, char **argv, t_stack *t_stack);
t_nodes	*init_node(long num);
void	free_split(char **arg_split);
bool	node_loop(int argc, t_stack *t_stack, char **arg_split, int i);
bool	args2array(int argc, char **argv, t_stack *t_stack);

void	normal(t_stack *t_stack);
long	normal_search(t_stack *t_stack, long prev);

void	swap(t_nodes *stack);
void	sa(t_stack *t_stack);
void	sb(t_stack *t_stack);
void	ss(t_stack *t_stack);

void	pa(t_stack *t_stack);
void	pb(t_stack *t_stack);

void	rotate(t_nodes *stack);
void	ra(t_stack *t_stack);
void	rb(t_stack *t_stack);
void	rr(t_stack *t_stack);

void	reverse(t_nodes *stack);
void	rra(t_stack *t_stack);
void	rrb(t_stack *t_stack);
void	rrr(t_stack *t_stack);

void	three(t_stack *t_stack);
void	five(t_stack *t_stack);

void	random2pos(t_stack *t_stack);
void	zero_first(t_stack *t_stack);
void	cost_algorithm(t_stack *t_stack);

void	calculate_pos(t_nodes *stack);
int		find_next(t_nodes *stack, long num);
void	targets(t_stack *t_stack);
int		ft_abs(int n);
int		min_cost(t_stack *t_stack);

int		total_cost(t_stack *t_stack, t_nodes *stack, int cost_a, int cost_b);
void	costs(t_stack *t_stack);


void	aubu(t_stack *t_stack, int target, int pos_cost);
void	adbd(t_stack *t_stack, int target, int pos_cost);
void	aubd(t_stack *t_stack, int target, int pos_cost);
void	adbu(t_stack *t_stack, int target, int pos_cost);
void	moving(t_stack *t_stack, int pos_cost);


#endif