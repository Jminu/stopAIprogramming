#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0) // child
	{
		close(fd[1]);
		dup2(fd[0], 0);
		execlp(argv[2], argv[2], (char*)0);
	}
	else if (pid > 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execlp(argv[1], argv[1], (char*)0);
	}
	return 0;
}
