/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/19 20:38:32 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h> // Flags EXIT_SUCCESS and EXIT_FAILURE
# include <unistd.h> // write
# include <stdio.h> // printf----------------------------------BORRAR?
# include <stdbool.h> // bool
# include <limits.h> // INT_MAX

typedef struct s_list
{
	long			num;
	int				pos;
	struct s_list	*next;
	struct s_list	*prev;
	int				cost;
}	t_list;

typedef struct s_stack
{
	//int	*stack_a;
	//int	*stack_b;
	t_list	*stack_a;
	t_list	*stack_b;
	int		count;
	int		len_a;
	int		len_b;
}	t_stack;

typedef enum e_ab
{
	A = 0,
	B = 1
}	t_ab;

void	check_num_args(int argc);
bool	args2array(int argc, char **argv, t_stack *t_stack);
bool	only_nums(char **args);
void	rep_nums(int *stack);
bool	sorted(t_stack *t_stack, int s);

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
int		*mins(t_stack *t_stack);
void	five(t_stack *t_stack);

#endif