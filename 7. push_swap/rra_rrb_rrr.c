/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:24 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/13 13:34:17 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_stack *t_stack, int s)
{
	int	aux;
	int	len;
	int	*stack;

	if (s == A)
	{
		len = t_stack->len_a;
		stack = t_stack->stack_a;
	}
	else
	{
		len = t_stack->len_b;
		stack = t_stack->stack_b;
	}
	aux = stack[len];
	len++;
	while (--len > 0)
		stack[len] = stack[len - 1];
	stack[0] = aux;
	if (s == A)
		t_stack->stack_a = stack;
	else
		t_stack->stack_b = stack;
}

void	rrr(t_stack *t_stack)
{
	rra_rrb(t_stack, A);
	rra_rrb(t_stack, B);
}
