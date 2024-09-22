/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:24 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/22 19:35:53 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *t_stack)
{
	t_nodes	*stack;
	long	aux;
	int		i;

	stack = t_stack->stack_a;
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
	t_stack->stack_a = stack;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *t_stack)
{
	t_nodes	*stack;
	long	aux;
	int		i;

	stack = t_stack->stack_b;
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
	t_stack->stack_b = stack;
	write(1, "rrb\n", 3);
}

void	rrr(t_stack *t_stack)
{
	rra(t_stack);
	rrb(t_stack);
	write(1, "rrr\n", 3);
}
