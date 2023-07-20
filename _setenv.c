#include <stdlib.h>
#include <string.h>

int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char **new_environ;
	char *var, *new_var;
	size_t name_len, value_len;
	int i, j;

	if (name == NULL || value == NULL || *name == '\0' || *value == '\0')
		return (-1);

	name_len = strlen(name);
	value_len = strlen(value);

	var = getenv(name);

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

	if (var == NULL || overwrite != 0)
	{
		new_var = malloc(sizeof(*new_var) * (name_len + value_len + 2));
		if (new_var == NULL)
			return (-1);
		strcpy(new_var, name);
		new_var[name_len] = '=';
		strcat(new_var, value);
	}

	if (var != NULL && overwrite != 0)
	{
		environ[i] = new_var;
	}
	else if (var == NULL)
	{
		new_environ = malloc(sizeof(*new_environ) * (i + 2));
		if (new_environ == NULL)
			return (-1);
		memcpy(new_environ, environ, 8 * 25);
		new_environ[i] = new_var;
		environ = new_environ;
	}

	return (0);
}
