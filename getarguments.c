#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include <unistd.h>

int main(void)
{
	char *buff, *buff_cpy;
	size_t n, len;
	char *token;
	int ac, i;
	char **av;

	buff = NULL;
	n = 0;
	ac = 0;
	getline(&buff, &n, stdin);
	_strcpy(buff_cpy, buff);
	token = strtok(buff, "\n ");
	while (token != NULL)
	{
		ac++;
		token = strtok(NULL, "\n ");
	}
	av = malloc(sizeof(*av) * (ac + 1));
	av[ac] = NULL;
	i = 0;
	token = strtok(buff_cpy, "\n ");
	while (token != NULL)
	{
		len = _strlen(token);
		av[i] = malloc(sizeof(**av) * (len + 1));
		_strcpy(av[i], token);
		token = strtok(NULL, "\n ");
		i++;
	}
	execve(av[0], av, NULL);

	return (0);
}
