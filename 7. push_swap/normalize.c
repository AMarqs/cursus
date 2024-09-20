/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:41:50 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/20 20:43:55 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	normal_search(t_stack *t_stack, long prev)
{
	long		aux;
	static int	i;
	int			pos;
	int			pos_aux;
	t_nodes		*first;

	aux = LONG_MAX;
	pos = 0;
	pos_aux = 0;
	first = t_stack->stack_a;
	while (t_stack->stack_a)
	{
		if ((t_stack->stack_a->num < aux)
			&& (t_stack->stack_a->num > prev))
		{
			aux = t_stack->stack_a->num;
			pos_aux = pos;
		}
		t_stack->stack_a = t_stack->stack_a->next;
		pos++;
	}
	t_stack->stack_a = first;
	printf("pos_aux: %d\n", pos_aux);
	while (pos_aux-- > 0)
		t_stack->stack_a = t_stack->stack_a->next;
	t_stack->stack_a->num = i++;
	t_stack->stack_a = first;
	return (i - 1);
}

void	normal(t_stack *t_stack)
{
	t_nodes	*aux;
	long	prev;

	aux = t_stack->stack_a;
	while (t_stack->stack_a)
	{
		t_stack->stack_a->num += INT_MAX;
		t_stack->stack_a->num += 2;
		t_stack->stack_a = t_stack->stack_a->next;
	}
	t_stack->stack_a = aux;
	prev = -1;
	prev = normal_search(t_stack, prev);
	while (aux->next)
	{
		prev = normal_search(t_stack, prev);
		aux = aux->next;
	}
}
