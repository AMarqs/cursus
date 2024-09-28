/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:01 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:15:25 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random2pos(t_stack *stack)
{
	int	pos_min_cost;

	calculate_pos(stack->stack_b);
	calculate_pos(stack->stack_a);
	targets(stack);
	costs(stack);
	pos_min_cost = min_cost(stack);
	moving(stack, pos_min_cost);
}

void	zero_first(t_stack *stack)
{
	t_nodes	*aux_stack;
	int		pos;

	aux_stack = stack->stack_a;
	pos = 0;
	while (stack->stack_a)
	{
		if (stack->stack_a->num == 0)
		{
			pos = stack->stack_a->pos;
			break ;
		}
		stack->stack_a = stack->stack_a->next;
	}
	stack->stack_a = aux_stack;
	if (pos > stack->len_a / 2)
	{
		while (stack->stack_a->num != 0)
			rra(stack);
	}
	else
	{
		while (stack->stack_a->num != 0)
			ra(stack);
	}
}

void	cost_algorithm(t_stack *stack)
{
	while (stack->len_a > (stack->count / 2))
	{
		if (stack->stack_a->num <= (stack->count / 2))
			pb(stack);
		else
			ra(stack);
	}
	while (stack->len_a > 3)
	{
		if (stack->stack_a->num < stack->count - 3)
			pb(stack);
		else
			ra(stack);
	}
	three(stack);
	while (stack->len_b > 0)
		random2pos(stack);
	zero_first(stack);
}
