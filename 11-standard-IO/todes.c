#include <stdio.h>
#include <fcntl.h>

int main() {
    FILE *fp;
    int fd = open("data.dat", O_WRONLY|O_CREAT|O_TRUNC);
    
    printf("First file descriptor: %d\n", fd);
    fp = fdopen(fd, "w");
    fputs("TCP/IP SOCKET PROGRAMMING\n", fp);
    printf("Second file descriptor: %d\n", fileno(fp));
    fclose(fp);
    return 0;
}
