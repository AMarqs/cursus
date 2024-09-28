/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:12:45 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:25:40 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aubu(t_stack *stack, int target, int pos_cost)
{
	if (target != 0 && pos_cost != 0)
	{
		while (target != stack->len_a && pos_cost != stack->len_b)
		{
			rrr(stack);
			pos_cost++;
			target++;
		}
	}
	if (target == 0 || target == stack->len_a)
		while (pos_cost++ != stack->len_b)
			rrb(stack);
	else
		while (target++ != stack->len_a)
			rra(stack);
}

void	adbd(t_stack *stack, int target, int pos_cost)
{
	if (target != 0 && pos_cost != 0)
	{
		while (target != 0 && pos_cost != 0)
		{
			rr(stack);
			pos_cost--;
			target--;
		}
	}
	if (target == 0)
		while (pos_cost-- != 0)
			rb(stack);
	else
		while (target-- != 0)
			ra(stack);
}

void	aubd(t_stack *stack, int target, int pos_cost)
{
	if (target != 0 && pos_cost != 0)
	{
		while (target != stack->len_a && pos_cost != 0)
		{
			rra(stack);
			rb(stack);
			target++;
			pos_cost--;
		}
	}
	if (target == stack->len_a || target == 0)
		while (pos_cost-- != 0)
			rb(stack);
	else
		while (target++ != stack->len_a)
			rra(stack);
}

void	adbu(t_stack *stack, int target, int pos_cost)
{
	if (target != 0 && pos_cost != 0)
	{
		while (target != 0 && pos_cost != stack->len_b)
		{
			ra(stack);
			rrb(stack);
			target--;
			pos_cost++;
		}
	}
	if (target == stack->len_a || target == 0)
		while (pos_cost++ != stack->len_b)
			rrb(stack);
	else
		while (target-- != 0)
			ra(stack);
}

void	moving(t_stack *stack, int pos_cost)
{
	t_nodes		*stack_b;
	t_rotation	rotation;
	int			target;

	stack_b = stack->stack_b;
	while (pos_cost != stack_b->pos)
		stack_b = stack_b->next;
	rotation = stack_b->rotation;
	target = stack_b->target;
	if (target != 0 || pos_cost != 0)
	{
		if (rotation == AUBU)
			aubu(stack, target, pos_cost);
		else if (rotation == ADBD)
			adbd(stack, target, pos_cost);
		else if (rotation == AUBD)
			aubd(stack, target, pos_cost);
		else if (rotation == ADBU)
			adbu(stack, target, pos_cost);
	}
	pa(stack);
}
