/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:51:29 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/22 21:20:50 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *t_stack)
{
	int		i;
	t_nodes	*stackb;

	if (t_stack->len_b == 0)
		return ;
	i = 0;
	while (t_stack->stack_a->next)
	{
		t_stack->stack_a = t_stack->stack_a->next;
		i++;
	}
	t_stack->stack_a->next->num = t_stack->stack_a->num;
	while (i > 0)
	{
		t_stack->stack_a->num = t_stack->stack_a->prev->num;
		t_stack->stack_a = t_stack->stack_a->prev;
		i--;
	}
	t_stack->stack_a->num = t_stack->stack_b->num;
	stackb = t_stack->stack_b;
	while (t_stack->stack_b->next)
	{
		t_stack->stack_b->num = t_stack->stack_b->next->num;
		t_stack->stack_b = t_stack->stack_b->next;
	}
	t_stack->stack_b->next = NULL;
	t_stack->stack_b = stackb;
	t_stack->len_a++;
	t_stack->len_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *t_stack)
{
	int		i;
	t_nodes	*stacka;

	if (t_stack->len_a == 0)
		return ;
	i = 0;
	while (t_stack->stack_b->next)
	{
		t_stack->stack_b = t_stack->stack_b->next;
		i++;
	}
	t_stack->stack_b->next->num = t_stack->stack_b->num;
	while (i > 0)
	{
		t_stack->stack_b->next->num = t_stack->stack_b->num;
		t_stack->stack_b = t_stack->stack_b->prev;
		i--;
	}
	t_stack->stack_b->num = t_stack->stack_a->num;
	stacka = t_stack->stack_a;
	while (stacka->next)
	{
		stacka->num = stacka->next->num;
		stacka = stacka->next;
	}
	stacka->next = NULL;
	t_stack->stack_a = stacka;
	t_stack->len_a--;
	t_stack->len_b++;
	write(1, "pb\n", 3);
}
