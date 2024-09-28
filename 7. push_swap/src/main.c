/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:20 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 18:42:30 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	frees(t_stack *stack)
{
	t_nodes	*aux;

	if (stack->stack_a)
	{
		while (stack->stack_a)
		{
			aux = stack->stack_a->next;
			free(stack->stack_a);
			stack->stack_a = aux;
		}
	}
	free(stack);
}

bool	sorted(t_nodes *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->num > stack_a->next->num)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

t_stack	*main_check(int argc, char **argv, t_stack *stack)
{
	if (stack == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (!check_num_args(argc, argv))
	{
		write(2, "Error\n", 6);
		free(stack);
		exit(EXIT_FAILURE);
	}
	if (!args2array(argc, argv, stack) || !rep_nums(stack->stack_a))
	{
		write(2, "Error\n", 6);
		frees(stack);
		exit(EXIT_FAILURE);
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->count = 0;
	main_check(argc, argv, stack);
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
