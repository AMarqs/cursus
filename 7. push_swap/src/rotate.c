/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:05 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:34:23 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_nodes *stack_x)
{
	long	aux;

	aux = stack_x->num;
	while (stack_x->next)
	{
		stack_x->num = stack_x->next->num;
		stack_x = stack_x->next;
	}
	stack_x->num = aux;
}

void	ra(t_stack *stack)
{
	rotate(stack->stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	rotate(stack->stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	rotate(stack->stack_a);
	rotate(stack->stack_b);
	write(1, "rr\n", 3);
}
