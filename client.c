/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:29:36 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 20:40:32 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nbr = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr *= 10;
		nbr += str[i++] - 48;
	}
	return (nbr * sign);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message recieved.", 17);
	}
}

void	bits_sender(pid_t pid, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (av[2][i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if ((av[2][i] >> j & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(250);
		}
		i++;
	}
	j = -1;
	while (++j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 || av[2][0] == '\0')
		return (1);
	signal(SIGUSR1, &sig_handler);
	pid = ft_atoi(av[1]);
	bits_sender(pid, av);
	sleep(1);
	return (0);
}
