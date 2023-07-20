#include <stdio.h>

char *_getenv(const char *name);

int main(void)
{
	char *env_value;

	env_value = _getenv("NAME");
	if (env_value == NULL)
	{
		printf("Invalid environment variable name\n");
		return (1);
	}

	printf("%s\n", env_value);

	return (0);
}
