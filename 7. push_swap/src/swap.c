/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:50:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 20:05:10 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nodes *stack)
{
	long	aux;

	aux = stack->num;
	stack->num = stack->next->num;
	stack->next->num = aux;
}

void	sa(t_stack *t_stack)
{
	if (t_stack->len_a < 2)
		return ;
	swap(t_stack->stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *t_stack)
{
	if (t_stack->len_b < 2)
		return ;
	swap(t_stack->stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *t_stack)
{
	if (t_stack->len_a < 2)
		return ;
	swap(t_stack->stack_a);
	if (t_stack->len_b < 2)
		return ;
	swap(t_stack->stack_b);
	write(1, "ss\n", 3);
}
