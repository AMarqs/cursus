/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:21:06 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 20:21:58 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_cost(t_stack *t_stack, t_nodes *stack, int cost_a, int cost_b)
{
	int	total_cost;
	int	opt;

	if ((cost_a <= 0 && cost_b <= 0) || (cost_a >= 0 && cost_b >= 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			total_cost = ft_abs(cost_a);
		else
			total_cost = ft_abs(cost_b);
		if (cost_a < 0 || (cost_a == 0 && cost_b < 0))
			stack->rotation = ADBD;
		else
			stack->rotation = AUBU;
	}
	else
	{
		total_cost = ft_abs(cost_a) + ft_abs(cost_b);
		if (cost_a < 0)
			stack->rotation = ADBU;
		else
			stack->rotation = AUBD;
		if (ft_abs(cost_a) > (t_stack->len_b - ft_abs(cost_b)))
			opt = ft_abs(cost_a);
		else
			opt = t_stack->len_b - ft_abs(cost_b);
		if (opt < total_cost)
		{
			total_cost = opt;
			if (cost_a < 0 || (cost_a == 0 && cost_b < 0))
				stack->rotation = ADBD;
			else
				stack->rotation = AUBU;
		}
		if ((t_stack->len_a - ft_abs(cost_a)) > ft_abs(cost_b))
			opt = t_stack->len_a - ft_abs(cost_a);
		else
			opt = ft_abs(cost_b);
		if (opt < total_cost)
		{
			total_cost = opt;
			if (cost_a < 0 || (cost_a == 0 && cost_b < 0))
				stack->rotation = AUBU;
			else
				stack->rotation = ADBD;
		}
	}
	return (total_cost);
}

void	costs(t_stack *t_stack)
{
	t_nodes	*stack_b;
	int		cost_a;
	int		cost_b;

	stack_b = t_stack->stack_b;
	cost_a = 0;
	cost_b = 0;
	while (stack_b)
	{
		if ((t_stack->len_a - stack_b->target) > stack_b->target)
			cost_a = stack_b->target * -1;
		else
			cost_a = t_stack->len_a - stack_b->target;
		if ((t_stack->len_b - stack_b->pos) > stack_b->pos)
			cost_b = stack_b->pos * -1;
		else
			cost_b = t_stack->len_b - stack_b->pos;
		stack_b->cost = total_cost(t_stack, stack_b, cost_a, cost_b) + 1;
		stack_b = stack_b->next;
	}
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
