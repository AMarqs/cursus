/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:05 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/13 13:28:37 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack *t_stack, int s)
{
	int	aux;
	int	len;
	int	*stack;
	int	i;

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
	aux = stack[0];
	i = 0;
	while (i < len)
		stack[len] = stack[len + 1];
	stack[len] = aux;
	if (s == A)
		t_stack->stack_a = stack;
	else
		t_stack->stack_b = stack;
}

void	rr(t_stack *t_stack)
{
	ra_rb(t_stack, A);
	ra_rb(t_stack, B);
}
