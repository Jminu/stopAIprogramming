#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int flag;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *producer(void *data)
{
	pthread_mutex_lock(&mutex);
	printf("decoding success!\n");
	flag = 10;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);

	return 0;
}

void *consumer(void *data)
{
	pthread_mutex_lock(&mutex);
	while (flag != 10)
		pthread_cond_wait(&cond, &mutex);

	printf("video play start, flag = %d\n", flag);
	pthread_mutex_unlock(&mutex);

	return 0;
}

int main(void)
{
	pthread_t thread_1;
	pthread_t thread_2;

	pthread_create(&thread_1, 0, producer, 0);
	pthread_create(&thread_2, 0, consumer, 0);

	pthread_join(thread_1, 0);
	pthread_join(thread_2, 0);

	return 0;
}
