#include <stdio.h>

int main(int ac, char **av, char**env)
{
	extern char **environ;

	printf("address of env: %p\n", &env);
	printf("address of environ: %p\n", &environ);

	return (0);
}
