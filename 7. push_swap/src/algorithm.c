/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:06:01 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 14:00:52 by albmarqu         ###   ########.fr       */
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
			if (cost_a < 0 || (cost_a == 0 && cost_b < 0))
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

void	moving(t_stack *t_stack, int pos_cost)
{
	t_nodes		*stack_b;
	t_rotation	rotation;
	int			target;
	int			cost;

	// printf("stack B: %p\n", t_stack->stack_b);
	// printf("stack B next: %p\n", t_stack->stack_b->next);
	// fflush(stdout);
	stack_b = t_stack->stack_b;
	// printf("stack B: %p\n", stack_b);
	// fflush(stdout);
	while (pos_cost != stack_b->pos)
		stack_b = stack_b->next;
	rotation = stack_b->rotation;
	target = stack_b->target;
	cost = stack_b->cost; ////////////////////////////////
	if (target != 0 || pos_cost != 0)
	{
		if (rotation == AUBU)
		{
			if (target != 0 && pos_cost != 0)
			{
				while (target != t_stack->len_a && pos_cost != t_stack->len_b)
				{
					// printf("len: %d\n", t_stack->len_b);
					// fflush(stdout);
					rrr(t_stack);
					pos_cost++;
					target++;
				}
			}
			if (target == 0 || target == t_stack->len_a)
			{
				while (pos_cost != t_stack->len_b)
				{
					rrb(t_stack);
					pos_cost++;
				}
			}
			else
			{
				while (target != t_stack->len_a)
				{
					rra(t_stack);
					target++;
				}
			}
		}
		else if (rotation == ADBD)
		{
			if (target != 0 && pos_cost != 0)
			{
				while (target != 0 && pos_cost != 0)
				{
					rr(t_stack);
					pos_cost--;
					target--;
				}
			}
			if (target == 0)
			{
				while (pos_cost != 0)
				{
					rb(t_stack);
					pos_cost--;
				}
			}
			else
			{
				while (target != 0)
				{
					ra(t_stack);
					target--;
				}
			}
		}
		else if (rotation == AUBD)
		{
			if (target != 0 && pos_cost != 0)
			{
				while (target != t_stack->len_a && pos_cost != 0)
				{
					rra(t_stack);
					rb(t_stack);
					target++;
					pos_cost--;
				}
			}
			if (target == t_stack->len_a || target == 0)
			{
				while (pos_cost != 0)
				{
					rb(t_stack);
					pos_cost--;
				}
			}
			else
			{
				while (target != t_stack->len_a)
				{
					rra(t_stack);
					target++;
				}
			}
		}
		else if (rotation == ADBU)
		{
			if (target != 0 && pos_cost != 0)
			{
				while (target != 0 && pos_cost != t_stack->len_b)
				{
					ra(t_stack);
					rrb(t_stack);
					target--;
					pos_cost++;
				}
			}
			if (target == t_stack->len_a || target == 0)
			{
				while (pos_cost != t_stack->len_b)
				{
					rrb(t_stack);
					pos_cost++;
				}
			}
			else
			{
				while (target != 0)
				{
					ra(t_stack);
					target--;
				}
			}
		}
	}
	// printf("7stack B: %p\n", t_stack->stack_b);
	// printf("7stack B next: %p\n", t_stack->stack_b->next);
	// fflush(stdout);
	pa(t_stack);
	// printf("8stack B: %p\n", t_stack->stack_b);
	// printf("8stack B next: %p\n", t_stack->stack_b->next);
	// fflush(stdout);
}

void	zero_first(t_stack *t_stack)
{
	t_nodes	*stack;
	int	pos;

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

void	random2pos(t_stack *t_stack)
{
	int	pos_min_cost;

	// printf("1stack B: %p\n", t_stack->stack_b);
	// fflush(stdout);
	calculate_pos(t_stack->stack_b);
	// printf("2stack B: %p\n", t_stack->stack_b);
	// fflush(stdout);
	calculate_pos(t_stack->stack_a);
	// printf("3stack B: %p\n", t_stack->stack_b);
	// fflush(stdout);
	targets(t_stack);
	// printf("4stack B: %p\n", t_stack->stack_b);
	// fflush(stdout);
	costs(t_stack);
	// printf("5stack B: %p\n", t_stack->stack_b);
	// fflush(stdout);
	pos_min_cost = min_cost(t_stack);
	// printf("6stack B: %p\n", t_stack->stack_b);
	// fflush(stdout);
	moving(t_stack, pos_min_cost);
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
