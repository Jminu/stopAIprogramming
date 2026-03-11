#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *my_handler1(void *data)
{
	char hp[] = "010-2249-0939";
	char *p;
	char *saveptr;

	p = strtok_r(hp, "-", &saveptr);
	while (p)
	{
		printf("[%s]\n", p);
		sleep(1);
		p = strtok_r(0, "-", &saveptr);
	}
	return 0;
}

void *my_handler2(void *data)
{
	char ip[] = "192.168.0.1";
	char *p;
	char *saveptr;

	p = strtok_r(ip, ".", &saveptr);
	while (p)
	{
		printf("[%s]\n", p);
		sleep(1);
		p = strtok_r(0, ".", &saveptr);
	}
	return 0;
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, 0, my_handler1, 0);
	pthread_create(&thread2, 0, my_handler2, 0);

	pthread_join(thread1, 0);
	pthread_join(thread2, 0);

	return 0;
}
