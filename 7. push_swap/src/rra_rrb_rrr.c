/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:24 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 13:08:13 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_nodes *stack)
{
	long	aux;
	int		i;

	aux = stack->num;
	i = 0;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	aux = stack->num;
	while (i > 0)
	{
		stack->num = stack->prev->num;
		stack = stack->prev;
		i--;
	}
	stack->num = aux;
}

void	rra(t_stack *t_stack)
{
	reverse(t_stack->stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *t_stack)
{
	reverse(t_stack->stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *t_stack)
{
	reverse(t_stack->stack_a);
	reverse(t_stack->stack_b);
	write(1, "rrr\n", 4);
}
