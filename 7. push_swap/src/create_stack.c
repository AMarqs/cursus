/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:38:05 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/27 18:07:41 by albmarqu         ###   ########.fr       */
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
			exit(EXIT_FAILURE);
		}
		arg_split = ft_split(argv[1], ' ');
		t_stack->count--;
		while (arg_split[t_stack->count])
			t_stack->count++;
	}
	else
		arg_split = argv + 1;
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

bool	args2array(int argc, char **argv, t_stack *t_stack)
{
	char	**arg_split;
	int		i;
	long	num;
	t_nodes	*num1;
	int count;

	count = argc;
	t_stack->count = (count - 1);
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
	num1 = t_stack->stack_a;
	while (i < t_stack->count)
	{
		num = ft_atol(arg_split[i++]);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		t_stack->stack_a->next = init_node(num);
		if (t_stack->stack_a->next == NULL)
			return (false);
		t_stack->stack_a->next->prev = t_stack->stack_a;
		t_stack->stack_a = t_stack->stack_a->next;
	}
	t_stack->stack_a = num1;
	i = 0;
	if (argc == 2)
	{
		while (arg_split[i])
			free(arg_split[i++]);
		free(arg_split);
	}
	// frees(t_stack);
	// exit(EXIT_SUCCESS);
	return (true);
}
