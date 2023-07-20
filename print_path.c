#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	extern char **environ;
	char *dir;
	char *path;
	int i;

	path = getenv("PATH");
	dir = strtok(path, ":");
	if (dir == NULL)
		return (1);
	while(dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}

	return (0);
}
