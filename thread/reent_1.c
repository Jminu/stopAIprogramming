#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void foo(int *data)
{
	printf("count = %d\n", ++(*data));
}

void *my_handler1(void *data)
{
	static int count = 0;
	foo(&count);
	foo(&count);
	foo(&count);
}

void *my_handler2(void *data)
{
	static int count = 0;
        foo(&count);
        foo(&count);
}

int main()
{
	pthread_t tid1;
	pthread_t tid2;

	pthread_create(&tid1, 0, my_handler1, 0);
	pthread_create(&tid2, 0, my_handler2, 0);

	pthread_join(tid1, 0);
	pthread_join(tid2, 0);

	return 0;
}
