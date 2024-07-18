#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30

void read_childproc(int sig);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;

    pid_t pid;
    struct sigaction act;
    socklen_t addr_sz;
    int str_len, state;
    char buf[BUF_SIZE];

    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    state = sigaction(SIGCHLD, &act, 0);

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) return -1;
    listen(serv_sock, 5);

    while(1) {
        addr_sz = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &addr_sz);
        puts("new client connected...");

        pid = fork();

        if(pid != 0) {
            close(clnt_sock);
            // 소켓은 운영체제의 소유이기 때문에, 프로세스가 복사되더라도 소켓은 하나만 존재한다.
            // 이 때 하나의 소켓에 두 개의 파일 디스크립터가 존재하는 경우, 두 개의 파일 디스크립터가 모두 종료되어야 소켓이 소멸된다.
            // 따라서 fork 함수 호출 이후에는 서로에게 상관이 없는 소켓 파일 디스크립터를 닫아줘야 한다.
        } else {
            close(serv_sock);
            while((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0)
                write(clnt_sock, buf, str_len);
            close(clnt_sock);
            puts("client disconnected...");
            return 0;
        }
    }
    close(serv_sock);
    return 0;
}

void read_childproc(int sig) {
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    printf("removed proc id: %d\n", pid);
}
