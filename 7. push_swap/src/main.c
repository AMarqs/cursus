/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:20 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 19:46:06 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			free(t_stack->stack_a);
			t_stack->stack_a = aux;
		}
	}
	free(t_stack);
}

int	main(int argc, char **argv)
{
	t_stack	*t_stack;
	t_nodes	*prueba;

	t_stack = malloc(sizeof(t_stack));
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
	normal(t_stack);
	t_stack->len_a = t_stack->count;
	if (t_stack->len_a == 1 || sorted(t_stack->stack_a))
	{
		prueba = t_stack->stack_a;
		while (prueba)
		{
			printf("%ld ", prueba->num);
			prueba = prueba->next;
		}
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
	while (t_stack->stack_a)
	{
		printf("%ld\n", t_stack->stack_a->num);
		t_stack->stack_a = t_stack->stack_a->next;
	}
	frees(t_stack);
	return (0);
}
