#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char buff[1024];

	fd = open("myfifo", O_RDWR);
	write(fd, "hello\n", 6);
	return 0;
}
