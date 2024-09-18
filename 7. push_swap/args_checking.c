/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:57:07 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/18 18:09:58 by albmarqu         ###   ########.fr       */
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

char	**split_args(int argc, char **argv, t_stack *t_stack)
{
	char	**arg_split;

	if (argc == 2)
	{
		arg_split = ft_split(argv[1], ' ');
		t_stack->count--;
		while (arg_split[t_stack->count])
			t_stack->count++;
	}
	else
		arg_split = argv + 1;
	return (arg_split);
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

void	args2array(int argc, char **argv, t_stack *t_stack)
{
	char	**arg_split;
	int		i;

	t_stack->count = argc - 1;
	arg_split = split_args(argc, argv, t_stack);
	if (!only_nums(arg_split))
	{
		write(2, "Error\nWrong arguments\n", 22);
		exit(EXIT_FAILURE);
	}
	t_stack->stack_a = malloc((t_stack->count) * sizeof(int));
	if (t_stack->stack_a == NULL)
	{
		write(2, "Error\nFailed allocating memory\n", 31);
		free(t_stack);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < t_stack->count)
		t_stack->stack_a[i] = ft_atoi(arg_split[i]);
	if (argc == 2)
		free(arg_split);
}

void	rep_nums(int *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while (stack[j])
		{
			if (stack[i] == stack[j])
			{
				write(2, "Error\nRepeated numbers\n", 23);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
