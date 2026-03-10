#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int seconds;
	char line[128];
	char message[64];

	printf("Alarm>");
	fgets(line, sizeof line, stdin);
	sscanf(line, "%d %64[^\n]", &seconds, message);
	sleep(seconds);
	printf("(%d) %s\n", seconds, message);

	return 0;
}
