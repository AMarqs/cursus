/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:37:13 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:18:36 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack *stack)
{
	t_nodes	*stack_a;

	stack_a = stack->stack_a;
	if (stack->len_a == 2)
		sa(stack);
	else
	{
		if (stack_a->num > stack_a->next->num
			&& stack_a->num > stack_a->next->next->num)
			ra(stack);
		else if (stack_a->next->num > stack_a->num
			&& stack_a->next->num > stack_a->next->next->num)
			rra(stack);
		if (stack_a->num > stack_a->next->num)
			sa(stack);
		stack->stack_a = stack_a;
	}
}

void	five(t_stack *stack)
{
	while (stack->len_b < 2)
	{
		if (stack->stack_a->num == 0 || stack->stack_a->num == 1)
			pb(stack);
		else
			ra(stack);
	}
	if (stack->stack_b->num < stack->stack_b->next->num)
		sb(stack);
	if (!sorted(stack->stack_a))
		three(stack);
	pa(stack);
	pa(stack);
}
