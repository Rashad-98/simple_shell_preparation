#include <stdio.h>
#include <stdlib.h>

int _unsetenv(const char *name);

int main(void)
{
	extern char **environ;
	char *var;
	int i;

	var = getenv("NAME");
	printf("variable (NAME): %s\n", var);

	_unsetenv("NAME");

	var = getenv("NAME");
	if (var == NULL)
		printf("environment variable not found\n");
	else
		printf("variable (NAME): %s\n", var);

	return (0);
}
