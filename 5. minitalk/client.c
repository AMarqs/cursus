/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:31:46 by albmarqu          #+#    #+#             */
/*   Updated: 2024/08/04 22:35:09 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char2bin(int pid, char str)
{
	int		j;

	j = 0;
	while (j < 8)
	{
		if ((str & (0x01 << j)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1500);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;
	int		i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		i = 0;
		while (str[i])
		{
			char2bin (pid, str[i]);
			i++;
		}
		char2bin (pid, '\n');
	}
	else
	{
		ft_printf("Error: wrong number of arguments. \n");
		return (1);
	}
	return (0);
}
