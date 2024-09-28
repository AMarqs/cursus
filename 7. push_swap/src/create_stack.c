/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:38:05 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/28 16:54:12 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_args(int argc, char **argv, t_stack *t_stack)
{
	char	**arg_split;

	if (argc == 2)
	{
		if (argv[1][0] == 0)
		{
			write(2, "Error\n", 6);
			free(t_stack);
			exit(EXIT_FAILURE);
		}
		arg_split = ft_split(argv[1], ' ');
		t_stack->count = 0;
		while (arg_split[t_stack->count])
			t_stack->count++;
	}
	else
	{
		arg_split = argv + 1;
		t_stack->count = argc - 1;
	}
	return (arg_split);
}

t_nodes	*init_node(long num)
{
	t_nodes	*node;

	node = malloc(sizeof(t_nodes));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_split(char **arg_split)
{
	int	i;

	i = 0;
	while (arg_split[i])
		free(arg_split[i++]);
	free(arg_split);
}

bool	node_loop(int argc, t_stack *t_stack, char **arg_split, int i)
{
	long	num;

	num = ft_atol(arg_split[i]);
	t_stack->stack_a->next = init_node(num);
	if (num > INT_MAX || num < INT_MIN || t_stack->stack_a->next == NULL)
	{
		if (argc == 2)
			free_split(arg_split);
		return (false);
	}
	t_stack->stack_a->next->prev = t_stack->stack_a;
	t_stack->stack_a = t_stack->stack_a->next;
	return (true);
}

bool	args2array(int argc, char **argv, t_stack *t_stack)
{
	char	**arg_split;
	int		i;
	long	num;
	t_nodes	*first;

	arg_split = split_args(argc, argv, t_stack);
	if (!only_nums(arg_split))
		return (false);
	i = 0;
	num = ft_atol(arg_split[i++]);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	t_stack->stack_a = init_node(num);
	if (t_stack->stack_a == NULL)
		return (false);
	first = t_stack->stack_a;
	while (i < t_stack->count)
		if (!node_loop(argc, t_stack, arg_split, i++))
			return (false);
	t_stack->stack_a = first;
	if (argc == 2)
		free_split(arg_split);
	return (true);
}
