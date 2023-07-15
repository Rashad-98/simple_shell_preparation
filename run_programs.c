#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *av[] = {"/usr/bin/ls", "-l", "/tmp", NULL};
	int wstatus, i;
	pid_t pid;

	wstatus = 0;
	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
			if(execve(av[0], av, NULL) == -1)
				exit(1);
		else if (pid == -1)
			exit(1);
		if (wait(&wstatus) == -1)
			exit(1);
	}
	
	return (0);
}
