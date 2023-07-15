#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	char *buffer;
	int digits;
	
	fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
	if (fd < 0)
		return (-1);
	digits = 10;
	buffer = malloc(digits);
	read(fd, buffer, digits);
	printf("%s", buffer);

	return (0);
}
