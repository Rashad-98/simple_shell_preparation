#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *token;

	token = strtok(av[1], "-");

	while(token)
	{
		printf("%s", token);
		token = strtok(NULL, "-");
		if (token)
			printf(" ");
	}
	printf("\n");

	return (0);
}
