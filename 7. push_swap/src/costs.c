/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:21:06 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 19:07:34 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_dir(t_nodes *stack_b, int cost_a, int cost_b)
{
	if (ft_abs(cost_a) > ft_abs(cost_b))
		stack_b->cost = ft_abs(cost_a);
	else
		stack_b->cost = ft_abs(cost_b);
	if (cost_a < 0 || (cost_a == 0 && cost_b < 0))
		stack_b->rotation = ADBD;
	else
		stack_b->rotation = AUBU;
}

void	diff_dir2(t_stack *stack, t_nodes *stack_b, int cost_a, int cost_b)
{
	int	opt;

	if ((stack->len_a - ft_abs(cost_a)) > ft_abs(cost_b))
		opt = stack->len_a - ft_abs(cost_a);
	else
		opt = ft_abs(cost_b);
	if (opt < stack_b->cost)
	{
		stack_b->cost = opt;
		if (cost_a < 0 || (cost_a == 0 && cost_b < 0))
			stack_b->rotation = AUBU;
		else
			stack_b->rotation = ADBD;
	}
}

void	diff_dir1(t_stack *stack, t_nodes *stack_b, int cost_a, int cost_b)
{
	int	opt;

	stack_b->cost = ft_abs(cost_a) + ft_abs(cost_b);
	if (cost_a < 0)
		stack_b->rotation = ADBU;
	else
		stack_b->rotation = AUBD;
	if (ft_abs(cost_a) > (stack->len_b - ft_abs(cost_b)))
		opt = ft_abs(cost_a);
	else
		opt = stack->len_b - ft_abs(cost_b);
	if (opt < stack_b->cost)
	{
		stack_b->cost = opt;
		if (cost_a < 0 || (cost_a == 0 && cost_b < 0))
			stack_b->rotation = ADBD;
		else
			stack_b->rotation = AUBU;
	}
	diff_dir2(stack, stack_b, cost_a, cost_b);
}

void	total_cost(t_stack *stack, t_nodes *stack_b, int cost_a, int cost_b)
{
	if ((cost_a <= 0 && cost_b <= 0) || (cost_a >= 0 && cost_b >= 0))
		same_dir(stack_b, cost_a, cost_b);
	else
		diff_dir1(stack, stack_b, cost_a, cost_b);
}

void	costs(t_stack *stack)
{
	t_nodes	*stack_b;
	int		cost_a;
	int		cost_b;

	stack_b = stack->stack_b;
	cost_a = 0;
	cost_b = 0;
	while (stack_b)
	{
		if ((stack->len_a - stack_b->target) > stack_b->target)
			cost_a = stack_b->target * -1;
		else
			cost_a = stack->len_a - stack_b->target;
		if ((stack->len_b - stack_b->pos) > stack_b->pos)
			cost_b = stack_b->pos * -1;
		else
			cost_b = stack->len_b - stack_b->pos;
		total_cost(stack, stack_b, cost_a, cost_b);
		stack_b->cost++;
		stack_b = stack_b->next;
	}
}
