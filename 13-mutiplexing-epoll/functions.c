#include <sys/epoll.h>

int epoll_create(int size);
// 성공 시 epoll 파일 디스크립터, 실패 시 -1 반환
// 리눅스 커널 2.6.8 이후부터 size는 완전히 무시된다.
// 생성되는 리소스는 소켓과 마찬가지로 운영체제에 의해서 관리된다.

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
// 성공 시 0, 실패 시 -1 반환

// epfd:    관찰 대상을 등록 할 epoll 인스턴스의 파일 디스크립터.
// op:      관찰대상을 추가, 삭제 또는 변경 여부 지정
// fd:      등록할 관찰대상의 파일 디스크립터
// event:   관찰대상의 관찰 이벤트 유형

// op:      EPOLL_TRL_ADD / EPOLL_CTL_DEL / EPOLL_CTL_MOD

struct epoll_event {
    __uint32_t events;
    epoll_data_t data;
};

typedef union epoll_data {
    void *ptr;
    int fd;
    __uint32_t u32;
    __uint64_t u64;
} epoll_data_t;

// epoll_event.events
// EPOLLIN      수신할 데이터가 존재하는 상황
// EPOLLOUT     출력버퍼가 비워져서 당장 데이터를 전송할 수 있는 상황
// EPOLLPRI     OOB 데이터가 수신된 상황
// EPOLLRDHUP   연결이 종료되거나 Half-close가 진행된 상황
// EPOLLERR     에러가 발생한 상황
// EPOLLET      이벤트의 감지를 엣지 트리거 방식으로 동작시킴
// EPOLLONESHOT 이벤트가 한번 감지되면, 해당 파일 디스크립터에서는 더 이상 이벤트를 발생시키지 않는다. 따라서 epoll_ctl 함수의 두 번째 인자로 EPOLL_CTL_MOD를 전달해서 이벤트를 재설정해야한다.

int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
// 성공 시 이벤트가 발생한 파일 디스크립터의 수, 실패 시 -1 반환

// epfd:        이벤트 발생의 관찰 영역인 epoll 인스턴스의 파일 디스크립터
// events:      이벤트가 발생한 파일 디스크립터가 채워질 버퍼의 주소 값
// maxevents:   두 번째 인자로 전달된 주소 값의 버퍼에 등록 가능한 최대 이벤트 수
// timeout:   1/1000초 단위의 대기시간, -1 전달 시 이벤트가 발생할 때까지 무한 대기

#include <fcntl.h>

int fcntl(int filedes, int cmd, ...);
// 성공 시 매개변수 cmd에 따른 값, 실패 시 -1 반환

// filedes: 특성변경의 대상이 되는 파일의 파일 디스크립터
// cmd:     함수 호출의 목적에 해당하는 정보

fcntl(fd, F_SETOWN, pid);
// fd가 가리키는 파일의 소유자를 pid로 변경

int flag = fcntl(fd, F_GETFL, 0);
// fd가 가리키는 파일의 특성 정보를 int형으로 얻음

fcntl(fd, F_SETFL, flag|O_NONBLOCK);
// fd가 가리키는 파일에 O_NONBLOCK 특성을 추가함
