#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd[2];
	int pid;
	char msgout[] = "Hello World!\n";
	char msgin[20];

	pipe(fd);
	pid = fork();
	if (pid > 0)
	{
		close(fd[0]);
		write(fd[1], msgout, sizeof(msgout));
	}
	else if (pid == 0)
	{
		close(fd[1]);
		int ret;
		while (ret = read(fd[0], msgin, 5))
			write(1, msgin, ret);
	}
	else
	{
		perror("fork error!\n");
		exit(1);
	}
	return 0;
}
