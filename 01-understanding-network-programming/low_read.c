#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100

int main(void) {
    int fd;
    char buf[BUF_SIZE] = {0, };

    fd = open("data.txt", O_RDONLY);
    printf("file descriptor: %d\n", fd);

    read(fd, buf, sizeof(buf));
    printf("file data: %s", buf);

    close(fd);
    return 0;
}
