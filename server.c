#include "minitalk.h"
#include <stdio.h>

void signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char c;
	static char counter;

	if (sig == SIGUSR1) // bit 0
	{
		c = c | 0; // not necessery
		// printf("SIGUSR1 RECIVED");//////
	}
	else if (sig == SIGUSR2) // bit 1
	{
		c = c | 1;
		// printf("SIGUSR2 RECIVED");//////
	}
	counter++;
	if(counter == 8)
	{
		counter = 0;
		// printf("\ncharacter => %c | its ascci => %d\n", c, c);//////
		write(1, &c, 1);
		c = 0;
	}
	else
	{
		c = c << 1;
		// printf("==> %d \n", c);//////
	}
}

int main()
{
	pid_t pid;
	struct sigaction	sigact = { 0 };//////////////////

	sigact.sa_sigaction = &signal_handler; 
	sigact.sa_flags = SA_SIGINFO;
	// sigact.sa_mask = 0;
	if (sigaction(SIGUSR1, &sigact, NULL) != 0 || sigaction(SIGUSR2, &sigact, NULL) != 0)
		return (1);
	pid = getpid();
	printf("PID: %d\n", pid);/////////////
	while(1)
	{
		sleep(1);
	}
	return(0);
}
