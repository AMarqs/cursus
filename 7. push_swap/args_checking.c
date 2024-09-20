/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:57:07 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/20 18:46:40 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num_args(int argc)
{
	if (argc < 2)
	{
		write(2, "Error\nNo arguments\n", 19); // Con 0 argunmentos que tiene que hacer ??? (hoja evaluacion)
		exit(EXIT_FAILURE);
	}
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
			j++;
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

void	rep_nums(t_nodes *stack)
{
	long	aux;
	t_nodes	*aux1;
	t_nodes	*act;

	aux1 = stack;
	while (aux1)
	{
		aux = aux1->num;
		act = aux1->next;
		while (act)
		{
			if (aux == act->num)
			{
				write(2, "Error\nRepeated numbers\n", 23);
				// liberar cosas
				exit(EXIT_FAILURE);
			}
			act = act->next;
		}
		aux1 = aux1->next;
	}
}
