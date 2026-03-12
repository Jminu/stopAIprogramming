#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_sig(int signo)
{
	printf("signal number = %d\n", signo);
	alarm(1);
}

int main()
{
	signal(SIGALRM, my_sig);
	alarm(1);
	while (1);

	return 0;
}
