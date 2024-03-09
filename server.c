/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:29:28 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 20:29:29 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr < 10)
		ft_putchar(nbr + 48);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static char	counter;

	(void)context;
	if (sig == SIGUSR1)
		c = c | 0;
	else if (sig == SIGUSR2)
		c = c | 1;
	counter++;
	if (counter == 8)
	{
		counter = 0;
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		c = 0;
	}
	else
	{
		c = c << 1;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sigact;

	sigact.sa_sigaction = signal_handler;
	sigact.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sigact, NULL) != 0
		|| sigaction(SIGUSR2, &sigact, NULL) != 0)
		return (1);
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr((long)pid);
	write(1, "\n", 1);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
