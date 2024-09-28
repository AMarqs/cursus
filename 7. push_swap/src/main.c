/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:20 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:05:21 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	frees(t_stack *t_stack)
{
	t_nodes	*aux;

	if (t_stack->stack_a)
	{
		while (t_stack->stack_a)
		{
			aux = t_stack->stack_a->next;
			free(t_stack->stack_a);
			t_stack->stack_a = aux;
		}
	}
	free(t_stack);
}

bool	sorted(t_nodes *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	main_check(t_stack *t_stack, int argc, char **argv)
{
	if (t_stack == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (!check_num_args(argc) || !args2array(argc, argv, t_stack) || !rep_nums(t_stack->stack_a))
	{
		write(2, "Error\n", 6);
		frees(t_stack);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argv[1][0] == 0)
	{
		write(2, "Error2\n", 7);
		exit(EXIT_SUCCESS);
	}
		
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->count = 0;
	main_check(stack, argc, argv);
	normal(stack);
	stack->len_a = stack->count;
	if (stack->len_a == 1 || sorted(stack->stack_a))
	{
		frees(stack);
		exit(EXIT_SUCCESS);
	}
	stack->stack_b = NULL;
	stack->len_b = 0;
	if (stack->len_a == 2 || stack->len_a == 3)
		three(stack);
	else if (stack->len_a == 4 || stack->len_a == 5)
		five(stack);
	else
		cost_algorithm(stack);
	frees(stack);
	return (0);
}
