#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - same as 'which'
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *path, *file_path, *full_file_path;
	int i;
	size_t count;
	struct stat buff;

	path = getenv("PATH");

	file_path = strtok(path, ":");
	while (1)
	{	
		full_file_path = malloc(strlen(file_path) + strlen(av[1]) + 10);
		count = strlen(file_path);
		*(full_file_path + count) = '/';
		for (i = 0; i < count; i++)
		{
			*(full_file_path + i) = *(file_path + i);
		}
		for (i = count + 1; *(av[1] + i - 1 - count) != '\0'; i++)
		{
			*(full_file_path + i) = *(av[1] + i - count - 1);
		}
		*(full_file_path + i) = '\0';
		if ( stat(full_file_path, &buff) == 0)
			printf("%s\n", full_file_path);
		free(full_file_path);
		file_path = strtok(NULL, ":");
		if (file_path == NULL)
			break;
	}

	return (0);
}
