#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE 4 
#define EPOLL_SIZE 50

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t addr_sz;
    int str_len, i;
    char buf[BUF_SIZE];

    struct epoll_event *ep_events;
    struct epoll_event event;
    int epfd, event_cnt;

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 5);

    epfd = epoll_create(EPOLL_SIZE);
    ep_events = (struct epoll_event*)malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

    event.events = EPOLLIN;
    event.data.fd = serv_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while(1) {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);

        puts("return epoll_wait");
        // epoll은 기본적으로 레벨 트리거 방식으로 작동
        // 레벨 트리거란, 입력 버퍼에 데이터가 남아있다면 계속해서 이벤트가 등록되는 것
        // 엣지 트리거는 클라이언트로부터 데이터가 수신될 때, 딱 한번만 이벤트가 등록된다
        // select도 기본적으로 레벨 트리거 방식으로 작동한다

        for(i = 0; i < event_cnt; i++) {
            if(ep_events[i].data.fd == serv_sock) {
                addr_sz = sizeof(clnt_addr);
                clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &addr_sz);
                // event.events = EPOLLIN;
                event.events = EPOLLIN | EPOLLET; // 엣지 트리거 모델로 변경
                event.data.fd = clnt_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
                printf("connected client: %d\n", clnt_sock);
            } else {
                clnt_sock = ep_events[i].data.fd;
                str_len = read(clnt_sock, buf, BUF_SIZE);
                if(str_len == 0) {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, clnt_sock, NULL);
                    close(clnt_sock);
                    printf("closed client: %d\n", clnt_sock); 
                } else {
                    write(clnt_sock, buf, str_len);
                }
            }
        }
    }
    close(serv_sock);
    close(epfd);
    return 0;
}

 
