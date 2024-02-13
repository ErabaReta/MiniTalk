#include <minitalk.h>
#include <stdio.h>

void *signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR1) // bit 0
		
}

int main()
{
	pid_t pid;
	struct sigaction	sigact;

	sigact.sa_sigaction = signal_handler; 
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_mask = 0;
	if (sigaction(SIGUSR1, &sigact, NULL) != 0 || sigaction(SIGUSR2, &sigact, NULL) != 0)
		return (1);
	pid = getpid();
	printf("PID: %d\n", pid);/////////////
	return(0);
}
