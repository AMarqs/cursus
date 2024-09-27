/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:05 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 13:00:50 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_nodes *stack)
{
	long	aux;

	aux = stack->num;
	while (stack->next)
	{
		stack->num = stack->next->num;
		stack = stack->next;
	}
	stack->num = aux;
}
	
void	ra(t_stack *t_stack)
{
	rotate(t_stack->stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *t_stack)
{
	rotate(t_stack->stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *t_stack)
{
	rotate(t_stack->stack_a);
	rotate(t_stack->stack_b);
	write(1, "rr\n", 3);
}
