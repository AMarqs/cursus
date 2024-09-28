/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:41:50 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:28:22 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	normal_search(t_stack *stack, long prev)
{
	long		aux;
	static int	i;
	t_nodes		*aux_stack;

	aux = LONG_MAX;
	aux_stack = stack->stack_a;
	while (stack->stack_a)
	{
		if ((stack->stack_a->num < aux) && (stack->stack_a->num > prev))
			aux = stack->stack_a->num;
		stack->stack_a = stack->stack_a->next;
	}
	stack->stack_a = aux_stack;
	while (stack->stack_a->num != aux)
		stack->stack_a = stack->stack_a->next;
	stack->stack_a->num = i++;
	stack->stack_a = aux_stack;
	return (i - 1);
}

void	normal(t_stack *stack)
{
	t_nodes	*aux_stack;
	long	prev;

	aux_stack = stack->stack_a;
	while (stack->stack_a)
	{
		stack->stack_a->num += INT_MAX;
		stack->stack_a->num += 2;
		stack->stack_a = stack->stack_a->next;
	}
	stack->stack_a = aux_stack;
	prev = -1;
	prev = normal_search(stack, prev);
	while (aux_stack->next)
	{
		prev = normal_search(stack, prev);
		aux_stack = aux_stack->next;
	}
}
