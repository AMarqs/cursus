/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:01 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/23 19:08:18 by albmarqu         ###   ########.fr       */
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
	}
}

void	costs(t_stack *t_stack)
{
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	if ((t_stack->len_b - t_stack->stack_b->pos) > t_stack->stack_b->pos)
		moves_b = t_stack->stack_b->pos;
	else
		moves_b = t_stack->len_b - t_stack->stack_b->pos;
	if ((t_stack->len_a - t_stack->stack_b->target) > t_stack->stack_b->target)
		moves_a = t_stack->stack_b->target;
	else
		moves_a = t_stack->len_a - t_stack->stack_b->target;
	t_stack->stack_b->cost = moves_a + moves_b + 1;
}

void	random2pos(t_stack *t_stack)
{
	calculate_pos(t_stack->stack_b);
	calculate_pos(t_stack->stack_a);
	targets(t_stack);
	costs(t_stack);
}

void	cost_algorithm(t_stack *t_stack)
{
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
}
