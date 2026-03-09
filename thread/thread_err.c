#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main()
{
	int fd;
	int ret;
	pthread_t thread = 0;
	ret = pthread_join(thread, 0);
	printf("ret = %d\n", ret);
	if (ret > 0)
	{
		printf("errno = %d\n", errno);
		printf("strerror = %s\n", strerror(ret));
	}

	return 0;
}
