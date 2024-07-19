#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define BUF_SIZE 30

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    int str_len;
    socklen_t clnt_addr_sz;
    char buf[BUF_SIZE];

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1])); 

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(serv_sock, 5);

    clnt_addr_sz = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_sz);

    while(1) {
        //str_len = recv(clnt_sock, buf, sizeof(buf) - 1, MSG_PEEK | MSG_DONTWAIT);
        str_len = recv(clnt_sock, buf, sizeof(buf) - 1, MSG_PEEK);
        if(str_len > 0)
            break;
    }

    buf[str_len] = 0;
    printf("Buffering %d bytes: %s\n", str_len, buf);

    str_len = recv(clnt_sock , buf, sizeof(buf) - 1, 0);
    buf[str_len] = 0;
    printf("Read again: %s\n", buf);

    close(clnt_sock);
    close(serv_sock);
    return 0;
}
