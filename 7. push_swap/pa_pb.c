/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:51:29 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/18 20:00:04 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *t_stack)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = t_stack->len_a - 1;
	len_b = t_stack->len_b - 1;
	if (len_b == -1)
		return ;
	while (len_a >= 0)
	{
		t_stack->stack_a[len_a + 1] = t_stack->stack_a[len_a];
		len_a--;
	}
	t_stack->stack_a[0] = t_stack->stack_b[0];
	i = 0;
	while (i < len_b)
	{
		t_stack->stack_b[i] = t_stack->stack_b[i + 1];
		i++;
	}
	t_stack->len_a++;
	t_stack->len_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *t_stack)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = t_stack->len_a - 1;
	len_b = t_stack->len_b - 1;
	if (len_a == -1)
		return ;
	while (len_b >= 0)
	{
		t_stack->stack_b[len_b + 1] = t_stack->stack_b[len_b];
		len_b--;
	}
	t_stack->stack_b[0] = t_stack->stack_a[0];
	i = 0;
	while (i < len_a)
	{
		t_stack->stack_a[i] = t_stack->stack_a[i + 1];
		i++;
	}
	t_stack->len_a--;
	t_stack->len_b++;
	write(1, "pb\n", 3);
}
