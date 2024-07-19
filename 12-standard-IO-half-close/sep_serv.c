#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    FILE *readfp, *writefp;
    
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    char buf[BUF_SIZE] = {0, };

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(serv_sock, 5);

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

    readfp = fdopen(clnt_sock, "r");
    // writefp = fdopen(dup(clnt_sock), "w");
    writefp = fdopen(clnt_sock, "w");

    fputs("FROM SERVER: HI~ clinet?\n", writefp);
    fputs("I love all of the world\n", writefp);
    fputs("You are awesome!\n", writefp);
    fflush(writefp);

    shutdown(fileno(writefp), SHUT_WR);

    fgets(buf, sizeof(buf), readfp);
    fputs(buf, stdout);
    close(clnt_sock);
    close(serv_sock);
    return 0;
}

