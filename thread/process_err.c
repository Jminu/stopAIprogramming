#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
	int fd;
	fd = open("aaa", O_RDONLY);
	if (fd < 0)
	{
		printf("errno = %d\n", errno);
		printf("strerror = %s\n", strerror(errno));
	}

	printf("fd = %d\n", fd);

	return 0;
}
