/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:01 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/24 13:16:36 by albmarqu         ###   ########.fr       */
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

int	ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

int	total_cost(t_stack *t_stack, t_nodes *stack, int cost_a, int cost_b)
{
	int	total_cost;
	int	opt;

	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			total_cost = cost_a;
		else
			total_cost = cost_b;
		if (cost_a < 0)
			stack->rotation = ADBD;
		else
			stack->rotation = AUBU;
	}
	else
	{
		total_cost = ft_abs(cost_a) + ft_abs(cost_b); // opcion 1: cada uno gira en su direccion
		if (cost_a < 0)
			stack->rotation = ADBU;
		else
			stack->rotation = AUBD;
		if (ft_abs(cost_a) > (t_stack->len_b - ft_abs(cost_b))) // opcion 2: a gira en su direccion y b en la contraria
			opt = ft_abs(cost_a);
		else
			opt = t_stack->len_b - ft_abs(cost_b);
		if (opt < total_cost)
		{
			total_cost = opt;
			if (cost_a < 0)
				stack->rotation = ADBD;
			else
				stack->rotation = AUBU;
		}
		if ((t_stack->len_a - ft_abs(cost_a)) > ft_abs(cost_b)) // opcion 3: a gira en la contraria y b en su direccion
			opt = t_stack->len_a - ft_abs(cost_a);
		else
			opt = ft_abs(cost_b);
		if (opt < total_cost)
		{
			total_cost = opt;
			if (cost_a < 0)
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

	stack_b = t_stack->stack_b;
	min_cost = INT_MAX;
	while (stack_b)
	{
		if (stack_b->cost < min_cost)
			min_cost = stack_b->cost;
		stack_b = stack_b->next;
	}
	return (min_cost);
}

void	moving(t_stack *t_stack, int minimum_cost)
{
	t_nodes	*stack_b;

	stack_b = t_stack->stack_b;
	while (stack_b)
	{
		if (stack_b->cost == minimum_cost)
		{
			while (stack_b->rotation > 0)
			{
				if (stack_b->rotation == AUBU)
					ra(t_stack);
				else if (stack_b->rotation == ADBD)
					rr(t_stack);
				else if (stack_b->rotation == AUBD)
					rra(t_stack);
				else if (stack_b->rotation == ADBU)
					rb(t_stack);
				stack_b->rotation--;
			}
			pa(t_stack);
			stack_b = t_stack->stack_b;
		}
		else
			stack_b = stack_b->next;
	}
}

void	random2pos(t_stack *t_stack)
{
	int	minimum_cost;

	calculate_pos(t_stack->stack_b);
	calculate_pos(t_stack->stack_a);
	targets(t_stack);
	costs(t_stack);
	minimum_cost = min_cost(t_stack);
	moving(t_stack, minimum_cost);
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
