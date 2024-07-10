#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	int fd;
	char buf[] = "Let's go!\n";

	fd = open("data.txt", O_CREAT|O_RDWR|O_TRUNC);
	printf("file descriptor: %d\n", fd);

	write(fd, buf, sizeof(buf) - 1);
	
	close(fd);
	return 0;
}
