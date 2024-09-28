/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:50:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 17:35:08 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nodes *stack_x)
{
	long	aux;

	aux = stack_x->num;
	stack_x->num = stack_x->next->num;
	stack_x->next->num = aux;
}

void	sa(t_stack *stack)
{
	if (stack->len_a < 2)
		return ;
	swap(stack->stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	if (stack->len_b < 2)
		return ;
	swap(stack->stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	if (stack->len_a < 2)
		return ;
	swap(stack->stack_a);
	if (stack->len_b < 2)
		return ;
	swap(stack->stack_b);
	write(1, "ss\n", 3);
}
