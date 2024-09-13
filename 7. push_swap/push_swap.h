/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/13 13:36:49 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h> // Flags EXIT_SUCCESS and EXIT_FAILURE
# include <unistd.h> // write
# include <stdio.h> // printf----------------------------------BORRAR?
# include <stdbool.h> // bool

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	count;
	int	len_a;
	int	len_b;
}	t_stack;

typedef enum e_ab
{
	A = 0,
	B = 1
}	t_ab;

void	check_num_args(int argc);
void	args2array(int argc, char **argv, t_stack *t_stack);
bool	only_nums(char **args);
void	rep_nums(int *stack);
bool	sorted(t_stack *t_stack);

void	sa(t_stack *t_stack);
void	sb(t_stack *t_stack);
void	ss(t_stack *t_stack);
void	pa(t_stack *t_stack);
void	pb(t_stack *t_stack);
void	ra_rb(t_stack *t_stack, int s);
void	rr(t_stack *t_stack);
void	rra_rrb(t_stack *t_stack, int s);
void	rrr(t_stack *t_stack);


#endif