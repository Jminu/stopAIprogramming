#include <stdio.h>
#include <string.h>

int main()
{
	char hp[] = "010-2249-0939";
	char *p;

	p = strtok(hp, "-");
	while (p)
	{
		printf("[%s]\n", p);
		p = strtok(0, "-");
	}
	return 0;
}
