#include <stdio.h>
#include <pthread.h>

int sum = 0;
pthread_mutex_t mutex;

void *foo(void *data)
{
	int local;
	int i;

	for (i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		local = sum;
		local = local + 1;
		sum = local;
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}

int main()
{
	pthread_mutex_init(&mutex, 0);
	pthread_t thread_1;
	pthread_t thread_2;

	pthread_create(&thread_1, 0, foo, 0);
	pthread_create(&thread_2, 0, foo, 0);

	pthread_join(thread_1, 0);
	pthread_join(thread_2, 0);

	printf("sum = %d\n", sum);

	return 0;
}
