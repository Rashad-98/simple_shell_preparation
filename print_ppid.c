#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t my_parent_pid;

	my_parent_pid = getppid();
	printf("%u\n", my_parent_pid);

	return (0);
}
