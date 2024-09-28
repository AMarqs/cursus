/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:27:54 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:31:20 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_pos(t_nodes *stack_x)
{
	int	pos;

	pos = 0;
	while (stack_x)
	{
		stack_x->pos = pos;
		stack_x = stack_x->next;
		pos++;
	}
}

int	find_next(t_nodes *stack_a, long num)
{
	long	big;
	int		pos;

	pos = -1;
	big = LONG_MAX;
	while (stack_a)
	{
		if (stack_a->num > num && stack_a->num < big)
		{
			big = stack_a->num;
			pos = stack_a->pos;
		}
		stack_a = stack_a->next;
	}
	return (pos);
}

void	targets(t_stack *stack)
{
	t_nodes	*stack_b;

	stack_b = stack->stack_b;
	while (stack_b)
	{
		stack_b->target = find_next(stack->stack_a, stack_b->num);
		stack_b = stack_b->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

int	min_cost(t_stack *stack)
{
	t_nodes	*stack_b;
	int		min_cost;
	int		pos_cost;

	stack_b = stack->stack_b;
	min_cost = INT_MAX;
	pos_cost = 0;
	while (stack_b)
	{
		if (stack_b->cost < min_cost)
		{
			min_cost = stack_b->cost;
			pos_cost = stack_b->pos;
		}
		stack_b = stack_b->next;
	}
	return (pos_cost);
}
