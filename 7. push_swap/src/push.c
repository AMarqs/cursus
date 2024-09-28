/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:51:29 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:32:53 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack)
{
	t_nodes	*aux;

	if (stack->len_b == 0)
		return ;
	if (stack->stack_a == NULL)
	{
		stack->stack_a = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		stack->stack_a->next = NULL;
	}
	else
	{
		aux = stack->stack_a;
		stack->stack_a = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		stack->stack_a->next = aux;
		stack->stack_a->next->prev = stack->stack_a;
	}
	if (stack->stack_b)
		stack->stack_b->prev = NULL;
	stack->len_a++;
	stack->len_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_nodes	*aux;

	if (stack->len_a == 0)
		return ;
	if (stack->stack_b == NULL)
	{
		stack->stack_b = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		stack->stack_b->next = NULL;
	}
	else
	{
		aux = stack->stack_b;
		stack->stack_b = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		stack->stack_b->next = aux;
		stack->stack_b->next->prev = stack->stack_b;
	}
	if (stack->stack_a)
		stack->stack_a->prev = NULL;
	stack->len_a--;
	stack->len_b++;
	write(1, "pb\n", 3);
}
