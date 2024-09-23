/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:51:29 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/23 17:34:48 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *t_stack)
{
	t_nodes	*aux;

	if (t_stack->len_b == 0)
		return ;
	if (t_stack->stack_a == NULL)
	{
		t_stack->stack_a = t_stack->stack_b;
		t_stack->stack_b = t_stack->stack_b->next;
		t_stack->stack_a->next = NULL;
	}
	else
	{
		aux = t_stack->stack_a;
		t_stack->stack_a = t_stack->stack_b;
		t_stack->stack_b = t_stack->stack_b->next;
		t_stack->stack_a->next = aux;
	}
	if (t_stack->stack_b)
		t_stack->stack_b->prev = NULL;
	t_stack->len_a++;
	t_stack->len_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *t_stack)
{
	t_nodes	*aux;

	if (t_stack->len_a == 0)
		return ;
	if (t_stack->stack_b == NULL)
	{
		t_stack->stack_b = t_stack->stack_a;
		t_stack->stack_a = t_stack->stack_a->next;
		t_stack->stack_b->next = NULL;
	}
	else
	{
		aux = t_stack->stack_b;
		t_stack->stack_b = t_stack->stack_a;
		t_stack->stack_a = t_stack->stack_a->next;
		t_stack->stack_b->next = aux;
	}
	if (t_stack->stack_a)
		t_stack->stack_a->prev = NULL;
	t_stack->len_a--;
	t_stack->len_b++;
	write(1, "pb\n", 3);
}
