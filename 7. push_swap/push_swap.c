/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:20 by albmarqu          #+#    #+#             */
/*   Updated: 2024/09/22 15:41:01 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack *t_stack, int s)
{
	t_nodes	*stack;

	if (s == A)
		stack = t_stack->stack_a;
	else
		stack = t_stack->stack_b;
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*t_stack;
	t_nodes	*original;

	t_stack = malloc(sizeof(t_stack));
	if (t_stack == NULL)
	{
		write(2, "Error\nFailed allocating memory\n", 31);
		exit(EXIT_FAILURE);
	}
	check_num_args(argc);
	args2array(argc, argv, t_stack);
	if (!args2array(argc, argv, t_stack))
	{
		write(2, "Error\n...n", 22);
		// free nodos....
		exit(EXIT_FAILURE);
	}
	//free(node)
	rep_nums(t_stack->stack_a);
	printf("count: %d\n", t_stack->count);
	original = t_stack->stack_a;
	normal(t_stack);
	t_stack->stack_a = original;
	printf("normalizado: ");
	while(t_stack->stack_a)
	{
		printf("%ld ", t_stack->stack_a->num);
		t_stack->stack_a = t_stack->stack_a->next;
	}
	printf("\n");
	t_stack->stack_a = original;
	t_stack->len_a = t_stack->count;
	if (t_stack->len_a == 1 || sorted(t_stack, A))
	{
	 	write(1, "ordenados\n", 10); // QUITARRRRR
	// 	free(t_stack->stack_a);
	// 	free(t_stack);
	 	return (0);
	}
	write(1, "desordenados\n", 13); // QUITARRRRR

	
/////////


	t_stack->stack_b = malloc((t_stack->len_a) * sizeof(int));
	t_stack->len_b = 0;
	// free t_stack, stack_a and stack_b
	if (t_stack->len_a == 2 || t_stack->len_a == 3)
		three(t_stack);



		
	// else if (t_stack->len_a == 4 || t_stack->len_a== 5)
	// 	five(t_stack);
	// //else
	// 	//many(t_stack);
	// int i = 0;
	// printf("\n");
    // while (i < t_stack->len_a)
    // {
    //     printf("%d ", t_stack->stack_a[i]);
    //     i++;
    // }
	// printf("\n");
	// //free(t_stack->stack_a);
	// //free(t_stack->stack_b);
	// free(t_stack);
	return (0);
}

// PONER TODOS LOS ERRORES SOLO ERROR
