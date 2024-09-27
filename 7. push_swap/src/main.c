/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:20 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 22:29:24 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	frees(t_stack *t_stack)
{
	t_nodes	*aux;

	if (t_stack->stack_b)
	{
		while (t_stack->stack_b)
		{
			aux = t_stack->stack_b->next;
			free(t_stack->stack_b);
			t_stack->stack_b = aux;
		}
	}
	if (t_stack->stack_a)
	{
		while (t_stack->stack_a)
		{
			aux = t_stack->stack_a->next;
			printf("a %p\n", t_stack->stack_a);
			fflush(stdout);
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
	check_num_args(argc);
	if (!args2array(argc, argv, t_stack) || !rep_nums(t_stack->stack_a))
	{
		write(2, "Error\n", 6);
		frees(t_stack);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*t_stack;

	t_stack = malloc(sizeof(t_stack));
	main_check(t_stack, argc, argv);
	normal(t_stack);
	t_stack->len_a = t_stack->count;
	if (t_stack->len_a == 1 || sorted(t_stack->stack_a))
	{
		frees(t_stack);
		exit(EXIT_SUCCESS);
	}
	t_stack->stack_b = NULL;
	t_stack->len_b = 0;
	if (t_stack->len_a == 2 || t_stack->len_a == 3)
		three(t_stack);
	else if (t_stack->len_a == 4 || t_stack->len_a == 5)
		five(t_stack);
	else
		cost_algorithm(t_stack);
	frees(t_stack);
	return (0);
}
