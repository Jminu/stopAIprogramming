#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo)
{
	printf("Child die : PID = %d\n", getpid());
}

int main()
{
	signal(SIGINT, handler);
	pause();
	return 0;
}
