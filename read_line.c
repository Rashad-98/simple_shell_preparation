#include <stdio.h>

int main(void)
{
	char *buffer;
	int count, i;
	size_t size;

	buffer = NULL;
	size = 0;
	printf("$ ");
	count = getline(&buffer, &size, stdin);
	if (count < 0)
		return(-1);

	for (i = 0; i < count; i++)
		putchar(*(buffer + i));

	return (0);
}
