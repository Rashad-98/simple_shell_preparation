#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer;
	char *path;
	int count, i, wstatus;
	size_t size;
	pid_t pid;

	while(1)
	{
		buffer = NULL;
		size = 0;
		printf("$ ");
		count = getline(&buffer, &size, stdin);
		path = malloc(count);
		for (i = 0; i < count - 1; i++)
		{
			*(path + i) = *(buffer + i);
		}
		*(path + i) = '\0';
		pid = fork();
		if (pid == 0)
		{
			char *const av[] = {path, NULL};
			execve(path, av, NULL);
		}
		else if (pid == -1)
		{
			printf("Error occured\n");
		}
		wait(&wstatus);
	}

	return (0);
}

