/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:05 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/18 19:19:54 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *t_stack)
{
	int	aux;
	int	len;
	int	*stack;
	int	i;

	len = t_stack->len_a - 1;
	stack = t_stack->stack_a;
	aux = stack[0];
	i = -1;
	while (++i < len)
		stack[i] = stack[i + 1];
	stack[len] = aux;
	t_stack->stack_a = stack;
	write(1, "ra\n", 3);
}

void	rb(t_stack *t_stack)
{
	int	aux;
	int	len;
	int	*stack;
	int	i;

	len = t_stack->len_b - 1;
	stack = t_stack->stack_b;
	aux = stack[0];
	i = -1;
	while (++i < len)
		stack[i] = stack[i + 1];
	stack[len] = aux;
	t_stack->stack_b = stack;
	write(1, "rb\n", 3);
}

void	rr(t_stack *t_stack)
{
	ra(t_stack);
	rb(t_stack);
	write(1, "rr\n", 3);
}
