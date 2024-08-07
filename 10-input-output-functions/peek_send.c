#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in send_addr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&send_addr, 0, sizeof(send_addr));
    send_addr.sin_family = AF_INET;
    send_addr.sin_addr.s_addr = inet_addr(argv[1]);
    send_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&send_addr, sizeof(send_addr)) == -1) {
        puts("connect() error!");
        exit(-1);
    }

    write(sock, "123", strlen("123"));

    close(sock);
    return 0;
}
