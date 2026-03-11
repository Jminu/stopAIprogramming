#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd;
	int ret;
	char buff[1024];

	fd = open("myfifo", O_RDWR);
	while (ret = read(fd, buff, sizeof buff))
		write(1, buff, ret);

	return 0;
}
