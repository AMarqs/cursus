/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:24 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/22 15:46:24 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *t_stack)
{
	int	aux;
	int	len;
	int	*stack;

	len = t_stack->len_a - 1;
	stack = t_stack->stack_a;
	aux = stack[len];
	len++;
	while (--len > 0)
		stack[len] = stack[len - 1];
	stack[0] = aux;
	t_stack->stack_a = stack;
	write(1, "rra\n", 3);
}

// void	rrb(t_stack *t_stack)
// {
// 	int	aux;
// 	int	len;
// 	int	*stack;

// 	len = t_stack->len_b - 1;
// 	stack = t_stack->stack_b;
// 	aux = stack[len];
// 	len++;
// 	while (--len > 0)
// 		stack[len] = stack[len - 1];
// 	stack[0] = aux;
// 	t_stack->stack_b = stack;
// 	write(1, "rrb\n", 3);
// }

// void	rrr(t_stack *t_stack)
// {
// 	rra(t_stack);
// 	rrb(t_stack);
// 	write(1, "rrr\n", 3);
// }
