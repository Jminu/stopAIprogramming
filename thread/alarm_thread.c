#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct alarm_tag
{
	int seconds;
	char message[64];
} alarm_t;

void *alarm_thread(void *data)
{
	alarm_t *alarm = (alarm_t*)data;
	pthread_detach(pthread_self());
	sleep(alarm->seconds);
	printf("(%d) %s\n", alarm->seconds, alarm->message);
	free(alarm);

	return 0;
}

int main()
{
	pthread_t thread1;
	char line[128];
	alarm_t *alarm;
	int read_len;

	while (1)
	{
		alarm = (alarm_t*)malloc(sizeof(alarm_t));
		printf("Alarm>");
		fflush(stdout);

		read_len = read(0, line, sizeof(line) - 1);
		if (read_len < 0)
		{
			free(alarm);
			break;
		}

		line[read_len] = '\0';
		sscanf(line, "%d %64[^\n]", &alarm->seconds, alarm->message);
		pthread_create(&thread1, 0, alarm_thread, alarm);
	}

	return 0;
}
