/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/24 13:07:35 by albmarqu         ###   ########.fr       */
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

bool	sorted(t_stack *t_stack, int s);

void	check_num_args(int argc);
bool	only_nums(char **args);
void	rep_nums(t_nodes *stack);

char	**split_args(int argc, char **argv, t_stack *t_stack);
t_nodes	*init_node(long num);
bool	args2array(int argc, char **argv, t_stack *t_stack);

void	normal(t_stack *t_stack);
long	normal_search(t_stack *t_stack, long prev);

void	sa(t_stack *t_stack);
void	sb(t_stack *t_stack);
void	ss(t_stack *t_stack);
void	pa(t_stack *t_stack);
void	pb(t_stack *t_stack);
void	ra(t_stack *t_stack);
void	rb(t_stack *t_stack);
void	rr(t_stack *t_stack);
void	rra(t_stack *t_stack);
void	rrb(t_stack *t_stack);
void	rrr(t_stack *t_stack);

void	three(t_stack *t_stack);
void	five(t_stack *t_stack);

void	calculate_pos(t_nodes *stack);
int		find_next(t_nodes *stack, long num);
void	targets(t_stack *t_stack);
int		ft_abs(int n);
int		total_cost(t_stack *t_stack, t_nodes *stack, int cost_a, int cost_b);
void	costs(t_stack *t_stack);
void	random2pos(t_stack *t_stack);
void	cost_algorithm(t_stack *t_stack);

#endif