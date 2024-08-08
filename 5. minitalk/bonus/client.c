/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:31:46 by albmarqu          #+#    #+#             */
/*   Updated: 2024/08/08 19:14:06 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	str2bin(char *str)
{
	static int	i;
	static int	j;
	int			signal;
	static char	*s;

	if (!s && str)
		s = str;
	if ((s[i] & (0x01 << j)) == 0x00)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	j++;
	if (j == 8)
	{
		j = 0;
		i++;
	}
	return (signal);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	int	pid;
	int	bit;

	(void)context;
	pid = info->si_pid;
	if (signal == SIGUSR1)
	{
		bit = str2bin(NULL);
		kill(pid, bit);
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("Signal received: 1 -> String completed\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					bit;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error: wrong number of arguments. \n");
		return (1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	pid = ft_atoi(argv[1]);
	bit = str2bin(argv[2]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	kill(pid, bit);
	while (1)
		pause();
	return (0);
}
