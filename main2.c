#include <stdlib.h>
#include <stdio.h>

int _setenv(const char *name, const char *value, int overwrite);

int main(void)
{
	char *var;

	var = getenv("NAME");
	printf("variable (NAME): %s\n", var);

	_setenv("country", "EGYPT", 1);
	var = getenv("country");
	printf("new variable (country): %s\n", var);

	_setenv("NAME", "Mohamed", 0);
	var = getenv("NAME");
	printf("not overwritten variable (NAME): %s\n", var);

	_setenv("NAME", "Abdelrahman", 1);
	var = getenv("NAME");
	printf("overwritten variable (NAME): %s\n", var);


	return (0);
}
