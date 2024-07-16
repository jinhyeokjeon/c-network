#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    char message[BUF_SIZE];
    int str_len, i;
    
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;

    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(serv_sock, 5);

    for(i = 0; i < 5; i++) {
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
        printf("Connected client: %d\n", i + 1);
        
        while((str_len = read(clnt_sock, message, BUF_SIZE)) != 0)
            write(clnt_sock, message, str_len);

        close(clnt_sock);
    }
    close(serv_sock);
    return 0;
}
