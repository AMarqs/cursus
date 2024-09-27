/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:01 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 20:28:53 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random2pos(t_stack *t_stack)
{
	int	pos_min_cost;

	calculate_pos(t_stack->stack_b);
	calculate_pos(t_stack->stack_a);
	targets(t_stack);
	costs(t_stack);
	pos_min_cost = min_cost(t_stack);
	moving(t_stack, pos_min_cost);
}

void	zero_first(t_stack *t_stack)
{
	t_nodes	*stack;
	int		pos;

	stack = t_stack->stack_a;
	pos = 0;
	while (t_stack->stack_a)
	{
		if (t_stack->stack_a->num == 0)
		{
			pos = t_stack->stack_a->pos;
			break ;
		}
		t_stack->stack_a = t_stack->stack_a->next;
	}
	t_stack->stack_a = stack;
	if (pos > t_stack->len_a / 2)
	{
		while (t_stack->stack_a->num != 0)
			rra(t_stack);
	}
	else
	{
		while (t_stack->stack_a->num != 0)
			ra(t_stack);
	}
}

void	cost_algorithm(t_stack *t_stack)
{
	while (t_stack->len_a > (t_stack->count / 2))
	{
		if (t_stack->stack_a->num <= (t_stack->count / 2))
			pb(t_stack);
		else
			ra(t_stack);
	}
	while (t_stack->len_a > 3)
	{
		if (t_stack->stack_a->num < t_stack->count - 3)
			pb(t_stack);
		else
			ra(t_stack);
	}
	three(t_stack);
	while (t_stack->len_b > 0)
		random2pos(t_stack);
	zero_first(t_stack);
}
