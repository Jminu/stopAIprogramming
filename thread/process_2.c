#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int g = 6;

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		printf("\t\t\t child : global = %d\n", ++g);
		exit(0);
	}

	wait(0);
	printf("parent : global = %d\n", g);

	return 0;
}
