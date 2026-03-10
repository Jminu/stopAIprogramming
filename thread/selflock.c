#include <stdio.h>
#include <pthread.h>

int sum = 0;
pthread_mutex_t mutex;

int fact(int n)
{
	if (n == 1)
		return 1;

	pthread_mutex_lock(&mutex);
	sum = n * fact(n - 1);
	pthread_mutex_unlock(&mutex);
	return sum;
}

int main()
{
	pthread_mutex_init(&mutex, 0);
	fact(5);
	printf("sum = %d\n", sum);

	return 0;
}
