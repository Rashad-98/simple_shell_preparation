#include <stdio.h>

int main(int ac, char **av)
{
	int i, j;

	for (i = 0; *(av + i) != NULL; i++)
	{
		for (j = 0; *(*(av + i) + j) != '\0'; j++)
		{
			putchar(*(*(av + i) + j));
		}
		putchar(10);
	}

	return (0);
}
