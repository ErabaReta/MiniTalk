/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:29:36 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/25 20:41:41 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid;

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1 && info->si_pid == g_pid)
	{
		write(1, "Message recieved.\n", 18);
		exit(0);
	}
}

void	bits_sender(pid_t pid, char **av)
{
	int		i;
	int		j;
	int		returned;

	i = 0;
	j = 0;
	while (av[2][i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if ((av[2][i] >> j & 1) == 0)
				returned = kill(pid, SIGUSR1);
			else
				returned = kill(pid, SIGUSR2);
			j--;
			if (returned == -1)
				exit(1);
			usleep(300);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sigact;
	int					i;

	sigact.sa_sigaction = signal_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) != 0
		|| sigaction(SIGUSR2, &sigact, NULL) != 0 || ac != 3)
		return (1);
	g_pid = ft_minitalk_atoi(av[1]);
	if (g_pid <= 1)
		return (1);
	bits_sender(g_pid, av);
	i = 0;
	while (i < 8)
	{
		kill(g_pid, SIGUSR1);
		usleep(300);
		i++;
	}
	sleep(1);
	return (0);
}
