#include <pthread.h>
#include <stdio.h>

void *foo(void *data)
{
	printf("\t\t\tchild : lobal = %d\n", ++*(int*)data);
	return 0;
}

int main(void)
{
	pthread_t thread;
	int local = 10;

	pthread_create(&thread, 0, foo, &local);
	pthread_join(thread, 0);

	printf("parent : lobal = %d\n", local);
	return 0;
}
