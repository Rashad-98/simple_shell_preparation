#include <stdlib.h>
#include <string.h>

int _unsetenv(const char *name)
{
	extern char **environ;
	char **new_environ;
	char *var;
	int i, j;
	int name_len, environ_len;

	if (name == NULL || *name == '\0')
		return (-1);
	var = getenv(name);
	if (var == NULL)
		return (0);

	name_len = strlen(name);
	environ_len = 0;
	for (i = 0; environ[i] != NULL; i++)
		environ_len++;
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < name_len; j++)
		{
			if (name[j] != environ[i][j])
				break;
		}
		if (j == name_len)
			break;
	}

	new_environ = malloc(sizeof(*new_environ) * environ_len - 1);
	if (new_environ == NULL)
		return (-1);
	memcpy(new_environ, environ, 8 * i);
	memcpy(new_environ + i, environ + i + 1, 8 * (environ_len - i + 1));
	environ = new_environ;

	return (0);
}
