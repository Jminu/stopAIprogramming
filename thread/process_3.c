#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int local;

	pid = fork();
	if (pid == 0)
	{
		printf("\t\t\t child : local = %d\n", ++local);
		exit(0);
	}

	wait(0);
	printf("parent : local = %d\n", local);

	return 0;
}
