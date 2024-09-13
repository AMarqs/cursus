/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:37:13 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/13 14:10:31 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack *t_stack) // 2 o 3 - max 3 movimientos
{
	int	*stack;

	stack = t_stack->stack_a;
	if (t_stack->len_a == 2)
		sa(t_stack);
	else
	{
		if (stack[2] > stack[1] && stack[2] > stack[0])
			rra_rrb(t_stack, A);
		else if (stack[0] > stack[1] && stack[0] > stack[2])
			ra_rb(t_stack, A);
		if (stack[0] > stack[1])
			sa(t_stack);
		t_stack->stack_a = stack;
	}
}

void	five(t_stack *t_stack) // 4 o 5 - max 12 movimientos
{
	// saco los 2 mas pequenos a B
}
