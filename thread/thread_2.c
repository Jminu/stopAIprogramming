#include <pthread.h>
#include <stdio.h>

int g = 6;

void *foo(void *data)
{
	printf("\t\t\tchild : global = %d\n", ++g);
	return 0;
}

int main(void)
{
	pthread_t thread;

	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0);

	printf("parent : global = %d\n", g);
	return 0;
}
