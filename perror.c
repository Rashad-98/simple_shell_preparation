#include <stdio.h>
#include <errno.h>

int main(void)
{
	errno = 2;
	perror("hello");
 	printf("hello again\n");
	return (0);
}
