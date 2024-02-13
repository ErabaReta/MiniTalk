#include <minitalk.h>
#include <string.h>
int main(int ac, char **av)
{
	pid_t	pid;
	int		len;
	int		i;
	char	*str;

	if (ac != 3)
		return (1);
	pid = atoi(av[1]);///////////////
	len = strlen(av[2]);/////////////
	if (len == 0)
		return (1);
	str = strdup(av[2]);//////////////
	i = 0;
	int j = 0;
	while (i < len)
	{
		j = 7;
		while(j >= 0)
		{
			if ((str[i] >> j & 1) == 0)
				kill(pid, SIGUSR1);// BIT 0
			else
				kill(pid, SIGUSR2);// BIT 1
			j--;
		}
		i++;
	}
	return (0);
}