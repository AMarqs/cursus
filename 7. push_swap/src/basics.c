/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:37:13 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 19:47:18 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack *t_stack)
{
	t_nodes	*stack;

	stack = t_stack->stack_a;
	if (t_stack->len_a == 2)
		sa(t_stack);
	else
	{
		if (stack->num > stack->next->num
			&& stack->num > stack->next->next->num)
			ra(t_stack);
		else if (stack->next->num > stack->num
			&& stack->next->num > stack->next->next->num)
			rra(t_stack);
		if (stack->num > stack->next->num)
			sa(t_stack);
		t_stack->stack_a = stack;
	}
}

void	five(t_stack *t_stack)
{
	while (t_stack->len_b < 2)
	{
		if (t_stack->stack_a->num == 0 || t_stack->stack_a->num == 1)
			pb(t_stack);
		else
			ra(t_stack);
	}
	if (t_stack->stack_b->num < t_stack->stack_b->next->num)
		sb(t_stack);
	if (!sorted(t_stack->stack_a))
		three(t_stack);
	pa(t_stack);
	pa(t_stack);
}
