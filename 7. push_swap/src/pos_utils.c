/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:27:54 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 21:41:23 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_pos(t_nodes *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

int	find_next(t_nodes *stack, long num)
{
	long	big;
	int		pos;

	pos = -1;
	big = LONG_MAX;
	while (stack)
	{
		if (stack->num > num && stack->num < big)
		{
			big = stack->num;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}

void	targets(t_stack *t_stack)
{
	t_nodes	*stack_b;

	stack_b = t_stack->stack_b;
	while (stack_b)
	{
		stack_b->target = find_next(t_stack->stack_a, stack_b->num);
		stack_b = stack_b->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

int	min_cost(t_stack *t_stack)
{
	t_nodes	*stack_b;
	int		min_cost;
	int		pos_cost;

	stack_b = t_stack->stack_b;
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
