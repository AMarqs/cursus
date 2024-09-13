/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:51:29 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/13 13:00:50 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *t_stack)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = t_stack->len_a;
	len_b = t_stack->len_b;
	if (len_b == 0)
		return ;
	while (len_a > 0)
	{
		t_stack->stack_a[len_a] = t_stack->stack_a[len_a - 1];
		len_a--;
	}
	t_stack->stack_a[0] = t_stack->stack_b[0];
	i = 0;
	while (i < len_b)
	{
		t_stack->stack_b[len_b] = t_stack->stack_b[len_b + 1];
		i++;
	}
	t_stack->len_a++;
	t_stack->len_b--;
}

void	pb(t_stack *t_stack)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = t_stack->len_a;
	len_b = t_stack->len_b;
	if (len_a == 0)
		return ;
	while (len_b > 0)
	{
		t_stack->stack_b[len_b] = t_stack->stack_b[len_b - 1];
		len_b--;
	}
	t_stack->stack_b[0] = t_stack->stack_a[0];
	i = 0;
	while (i < len_a)
	{
		t_stack->stack_a[len_a] = t_stack->stack_a[len_a + 1];
		i++;
	}
	t_stack->len_a--;
	t_stack->len_b++;
}
