#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signo)
{
	printf("SIGINT Receive\n");
	exit(0);
}

int main(void)
{
	signal(SIGINT, sig_handler);

	printf("1..\n");
	sleep(1);
	printf("1..\n");
	sleep(1);
	printf("1..\n");
	sleep(1);
	printf("1..\n");

	return 0;
}
