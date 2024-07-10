#include <sys/socket.h>

int socket(int domain, int type, int protocol);
// 소켓 생성 함수
// 성공 시 파일 디스크립터, 실패 시 -1 반환

int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
// 소켓에 주소정보 할당
// 성공 시 0, 실패 시 -1 반환

int listen(int sockfd, int backlog);
// 소켓을 연결요청 가능한 상태가 되도록 하는 함수
// 성공 시 0, 실패 시 -1 반화

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
// 연결 요청 수락
// 성공 시 파일 디스클비터, 실패 시 -1 반환

int connect(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);
// 연결 요청 함수
// 성공 시 0, 실패 시 -1 반환

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *path, int flag);
// 파일 여는 함수
// 성공 시 파일 디스크립터, 실패시 -1 반환
// path: 파일 이름을 나타내는 문자열의 주소 값 전달
// flag: 파일의 오픈 모드 정보 전달

#include <unistd.h>

int close(int fd);
// 파일 닫는 함수
// 성공 시 0, 실패 시 -1 반환

ssize_t write(int fd, const cond *buf, size_t nbytes);
// 파일에 데이터 출력하는 함수
// 성공 시 전달한 바이트 수, 실패 시 -1 반환
// fd: 파일 디스크립터
// buf: 전송할 데이터 저장된 버퍼의 주소 값
// nbytes: 전송할 데이터의 바이트 수
// size_t : 4바이트 unsigned 자료형 (unsigned int)
// ssize_t: 4바이트 signed 자료형   (signed int)

ssize_t read(int fd, void *buf, size_t nbytes);
// 파일로부터 데이터 읽는 함수
// 성공 시 수신한 바이트 수(단 파일 끝을 만나면 0), 실패 시 -1 반환
// fd: 파일 디스크립터
// buf: 수신한 데이터를 저장할 버퍼의 주소 값
// nbytes: 수신할 최대 바이트 수
