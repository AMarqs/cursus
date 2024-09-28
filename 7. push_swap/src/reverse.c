/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:24 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:33:43 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_nodes *stack_x)
{
	long	aux;
	int		i;

	aux = stack_x->num;
	i = 0;
	while (stack_x->next)
	{
		stack_x = stack_x->next;
		i++;
	}
	aux = stack_x->num;
	while (i > 0)
	{
		stack_x->num = stack_x->prev->num;
		stack_x = stack_x->prev;
		i--;
	}
	stack_x->num = aux;
}

void	rra(t_stack *stack)
{
	reverse(stack->stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	reverse(stack->stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	reverse(stack->stack_a);
	reverse(stack->stack_b);
	write(1, "rrr\n", 4);
}
