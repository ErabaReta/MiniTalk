#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid = getpid();
	printf("PID: %d\n", pid);
}