/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/12 20:35:08 by albmarqu         ###   ########.fr       */
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
}	t_stack;

void	check_num_args(int argc);
void	args2array(int argc, char **argv, t_stack *t_stack);
bool	only_nums(char **args);
void	rep_nums(int *stack);
bool	sorted(t_stack *t_stack);




//void	check_args(int argc, char **argv);







#endif