/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:50:14 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/13 11:59:31 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *t_stack)
{
	int	aux;

	if (t_stack->count < 2)
		return ;
	aux = t_stack->stack_a[0];
	t_stack->stack_a[0] = t_stack->stack_a[1];
	t_stack->stack_a[1] = aux;
}

void	sb(t_stack *t_stack)
{
	int	aux;

	if (t_stack->count < 2)
		return ;
	aux = t_stack->stack_b[0];
	t_stack->stack_b[0] = t_stack->stack_b[1];
	t_stack->stack_b[1] = aux;
}

void	ss(t_stack *t_stack)
{
	sa(t_stack);
	sb(t_stack);
}
