#include "minitalk.h"
#include <string.h>
#include <stdio.h>
int main(int ac, char **av)
{
	pid_t	pid;
	int		len;
	int		i;
	char	*str;

	if (ac != 3)
	{
		return (1);
	printf("ERROR not enough pars.\n");//////////////

	}
	pid = atoi(av[1]);///////////////
	printf("server's PID: %d\n", pid);//////////////
	len = strlen(av[2]);/////////////
	if (len == 0)
		return (1);
	str = strdup(av[2]);/////////////
	printf("string to send: %s\n", str);//////////////
	i = 0;
	int j = 0;
	while (i < len)
	{
		j = 7;
		while(j >= 0)
		{
			if ((str[i] >> j & 1) == 0)
			{
				kill(pid, SIGUSR1);// BIT 0
				printf("SIGUSR1 sent\n");
			}
			else
			{
				kill(pid, SIGUSR2);// BIT 1
				printf("SIGUSR2 sent\n");
			}
			j--;
			usleep(400);
		}
		i++;
	}
	
	return (0);
}