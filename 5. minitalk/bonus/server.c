/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:31:43 by albmarqu          #+#    #+#             */
/*   Updated: 2024/08/05 19:09:23 by albmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	int			pid;
	static char	c;
	static int	i;

	(void)context;
	pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (0x00 << i);
	else
		c |= (0x01 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			kill(pid, SIGUSR2);
		}
		else
			ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
