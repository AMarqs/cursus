/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:57:07 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/19 20:59:46 by albmarqu         ###   ########.fr       */
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

t_list	*init_node(long num)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

bool	args2array(int argc, char **argv, t_stack *t_stack)
{
	char	**arg_split;
	int		i;
	long	num;
	t_list	*num1;

	t_stack->count = argc - 1;
	arg_split = split_args(argc, argv, t_stack);
	if (!only_nums(arg_split))
	{
		write(2, "Error\nWrong arguments\n", 22);
		return (false);
	}
	i = 0;
	num = ft_atol(arg_split[i++]);
	if (num > INT_MAX || num < INT_MIN)
	{
		write(2, "Error\nNumber out of range\n", 26);
		return (false);
	}
	t_stack->stack_a = malloc(sizeof(t_list));
	if (t_stack->stack_a == NULL)
	{
		write(2, "Error\nFailed allocating memory\n", 31);
		return (false);
	}
	t_stack->stack_a = init_node(num);
	if (t_stack->stack_a == NULL)
		return (false);
	num1 = t_stack->stack_a;
	while (i < t_stack->count)
	{
		num = ft_atol(arg_split[i++]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write(2, "Error\nNumber out of range\n", 26);
			return (false);
		}
		t_stack->stack_a->next = init_node(num);
		if (t_stack->stack_a->next == NULL)
			return (false);
		t_stack->stack_a->next->prev = t_stack->stack_a;
		t_stack->stack_a = t_stack->stack_a->next;
	}
	t_stack->stack_a = num1;
	if (argc == 2)
		free(arg_split);
	return (true);
}

void	rep_nums(t_list *stack)
{
	long	aux;
	t_list	*aux1;
	t_list	*act;

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
