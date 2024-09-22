/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:37:13 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/22 15:51:28 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack *t_stack) // 2 o 3 - max 3 movimientos
{
	t_nodes	*stack;

	stack = t_stack->stack_a;
	if (t_stack->len_a == 2)
		sa(stack);
	else
	{
		if (stack->num > stack->next->num && stack->num > stack->next->next->num)
			ra(t_stack);
		else if (stack->next->num > stack->num && stack->next->num > stack->next->next->num)
			rra(t_stack);
		if (stack->num > stack->next->num)
			sa(t_stack);
		t_stack->stack_a = stack;
	}
}

// int	*mins(t_stack *t_stack)
// {
// 	int	i;
// 	int	*min;

// 	i = 1;
// 	min = malloc(2 * sizeof(int));
// 	min[0] = t_stack->stack_a[0];
// 	min[1] = INT_MAX;
// 	while (i < t_stack->len_a)
// 	{
// 		if (t_stack->stack_a[i] < min[0])
// 			min[0] = t_stack->stack_a[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < t_stack->len_a)
// 	{
// 		if (t_stack->stack_a[i] < min[1] && t_stack->stack_a[i] > min[0])
// 			min[1] = t_stack->stack_a[i];
// 		i++;
// 	}
// 	return (min);
// }

// void	five(t_stack *t_stack) // 4 o 5 - max 12 movimientos
// {
// 	int	i;
// 	int	*min;
// 	int	len;

// 	i = 0;
// 	min = mins(t_stack);
// 	len = t_stack->len_a;
// 	printf("min: %d, %d\n", min[0], min[1]); ////////////////////////////////
// 	while (i < len)
// 	{
// 		if (t_stack->stack_a[0] == min[0] || t_stack->stack_a[0] == min[1])
// 			pb(t_stack);
// 		else
// 			ra(t_stack);
// 		i++;
// 	}
// 	if (t_stack->stack_b[0] < t_stack->stack_b[1])
// 		sb(t_stack);
// 	if (!sorted(t_stack, A))
// 		three(t_stack);
// 	pa(t_stack);
// 	pa(t_stack);
// 	free(min);
// }
