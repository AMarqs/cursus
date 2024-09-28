/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:57:07 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 18:42:24 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_num_args(int argc, char **argv)
{
	if (argc < 2)
		return (false);
	if (argc == 2 && argv[1][0] == 0)
		return (false);
	return (true);
}

bool	only_nums(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-')
			if (!args[i][++j])
				return (false);
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	rep_nums(t_nodes *stack_a)
{
	long	aux;
	t_nodes	*aux_stack;
	t_nodes	*act;

	aux_stack = stack_a;
	while (aux_stack)
	{
		aux = aux_stack->num;
		act = aux_stack->next;
		while (act)
		{
			if (aux == act->num)
				return (false);
			act = act->next;
		}
		aux_stack = aux_stack->next;
	}
	return (true);
}
