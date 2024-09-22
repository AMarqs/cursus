/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:05 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/22 19:35:36 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *t_stack)
{
	t_nodes	*stack;
	long	aux;

	stack = t_stack->stack_a;
	aux = stack->num;
	while (stack->next)
	{
		stack->num = stack->next->num;
		stack = stack->next;
	}
	stack->num = aux;
	t_stack->stack_a = stack;
	write(1, "ra\n", 3);
}

void	rb(t_stack *t_stack)
{
	t_nodes	*stack;
	long	aux;

	stack = t_stack->stack_b;
	aux = stack->num;
	while (stack->next)
	{
		stack->num = stack->next->num;
		stack = stack->next;
	}
	stack->num = aux;
	t_stack->stack_b = stack;
	write(1, "rb\n", 3);
}

void	rr(t_stack *t_stack)
{
	ra(t_stack);
	rb(t_stack);
	write(1, "rr\n", 3);
}
