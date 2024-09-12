/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:20 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/12 20:37:02 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack *t_stack)
{
	int	i;

	i = 0;
	while (i < (t_stack->count - 1))
	{
		if (t_stack->stack_a[i] > t_stack->stack_a[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*t_stack;

	t_stack = malloc(sizeof(t_stack));
	if (t_stack == NULL)
	{
		write(2, "Error\nFailed allocating memory\n", 31);
		exit(EXIT_FAILURE);
	}
	check_num_args(argc);
	args2array(argc, argv, t_stack);
	rep_nums(t_stack->stack_a);
	if (t_stack->count == 1 || sorted(t_stack))
	{
		write(1, "ordenados", 9); // QUITARRRRR
		free(t_stack->stack_a);
		free(t_stack);
		return (0);
	}
	write(1, "desordenados", 12); // QUITARRRRR
	// free stack_a and t_stack
	free(t_stack->stack_a);
	free(t_stack);
	return (0);
}
