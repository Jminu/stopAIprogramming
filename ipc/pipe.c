#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd[2];
	pipe(fd);
	char buf[1024];
	int ret;

	printf("fd[0]=%d, fd[1]=%d\n", fd[0], fd[1]);

	write(fd[1], "hello", 5);
	ret = read(fd[0], buf, sizeof(buf));
	buf[ret] = '\0';

	write(1, buf, ret);

	close(fd[0]);
	close(fd[1]);

	return 0;
}
