#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
	int i;
	pid_t pid;
	pid_t pids[3];

	for (i = 0; i < 3; i++)
	{
		pid = fork();
		if (pid > 0)
			execlp("./sig_child", "./sig_child", (char*)0);

		pids[i] = pid;
	}

	sleep(5);
	for (i = 0; i < 3; i++)
		kill(pids[i], SIGINT);

	return 0;
}
