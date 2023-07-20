#include <string.h>

char *_getenv(const char *name)
{
	extern char **environ;
	size_t len;
	int i, j;

	len = strlen(name);

	if (len == 0)
		return NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (name[j] != environ[i][j])
				break;
		}
		if (j == len)
			return (&(environ[i][j + 1]));
	}

	return (NULL);
}
