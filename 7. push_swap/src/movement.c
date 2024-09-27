/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:12:45 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 20:44:17 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aubu(t_stack *t_stack, int target, int pos_cost)
{
	if (target != 0 && pos_cost != 0)
	{
		while (target != t_stack->len_a && pos_cost != t_stack->len_b)
		{
			rrr(t_stack);
			pos_cost++;
			target++;
		}
	}
	if (target == 0 || target == t_stack->len_a)
		while (pos_cost++ != t_stack->len_b)
			rrb(t_stack);
	else
		while (target++ != t_stack->len_a)
			rra(t_stack);
}

void	adbd(t_stack *t_stack, int target, int pos_cost)
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
		while (pos_cost-- != 0)
			rb(t_stack);
	else
		while (target-- != 0)
			ra(t_stack);
}

void	aubd(t_stack *t_stack, int target, int pos_cost)
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
		while (pos_cost-- != 0)
			rb(t_stack);
	else
		while (target++ != t_stack->len_a)
			rra(t_stack);
}

void	adbu(t_stack *t_stack, int target, int pos_cost)
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
		while (pos_cost++ != t_stack->len_b)
			rrb(t_stack);
	else
		while (target-- != 0)
			ra(t_stack);
}

void	moving(t_stack *t_stack, int pos_cost)
{
	t_nodes		*stack_b;
	t_rotation	rotation;
	int			target;

	stack_b = t_stack->stack_b;
	while (pos_cost != stack_b->pos)
		stack_b = stack_b->next;
	rotation = stack_b->rotation;
	target = stack_b->target;
	if (target != 0 || pos_cost != 0)
	{
		if (rotation == AUBU)
			aubu(t_stack, target, pos_cost);
		else if (rotation == ADBD)
			adbd(t_stack, target, pos_cost);
		else if (rotation == AUBD)
			aubd(t_stack, target, pos_cost);
		else if (rotation == ADBU)
			adbu(t_stack, target, pos_cost);
	}
	pa(t_stack);
}
