#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char buff[20];
	char *lineptr;
	size_t n;

	lineptr = NULL;
	n = 0;

	getline(&lineptr, &n, stdin);
	printf("%s", lineptr);

	//read(STDIN_FILENO, buff, 20);
	if (!isatty(STDIN_FILENO))
	{
		printf("that was a redirected input\n");
	}
	else
	{
		printf("prompt $ ");
	}

	return (0);
}
