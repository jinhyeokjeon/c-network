#include <sys/socket.h>

ssize_t send(int sockfd, const void *buf, size_t nbytes, int flags);
// 성공 시 전송 된 바이트 수, 실패 시 -1 반환

// sockfd:  데이터 전송 대상 소켓의 파일 디스크립터
// buf:     전송할 데이터를 저장하고 있는 버퍼의 주소 값
// nbytes:  전송할 바이트 수
// flags:   데이터 전송 시 적용할 다양한 옵션 정보

ssize_t recv(int sockfd, void *buf, size_t nbytes, int flags);
// 성공 시 수신한 바이트 수, EOF 수신 시 0, 실패 시 -1 반환

// sockfd:  데이터 수신 대상 소켓의 파일 디스크립터
// buf:     수신할 데이터를 저장할 버퍼의 주소 값
// nbytes:  수신할 수 있는 최대 바이트 수
// flags:   데이터 수신 시적용할 옵션 정보

// Option: MSG_OOB(긴급 데이터) / MSG_PEEK(입력 버퍼에 수신된 데이터 존재유무 확인) / MSG_DONTWAIT(입출력 함수 호출 과정에서 블로킹 되지 않게 함)

#include <sys/uio.h>

ssize_t writev(int filedes, const struct iovec *iov, int iovcnt);
// 성공 시 전송된 바이트 수, 실패 시 -1 반환

// filedes: 데이터 전송의 목적지를 나타내는 소켓의 파일 디스크립터
// iov:     구조체 iovec배열의 주소 값
// iovcnt:  iov 배열의 길이정보

ssize_t readv(int filedes, const struct iovec *iov, int iovcnt);
// 성공 시 수신된 바이트 수, 실패 시 -1 반환

// filedes: 데이터를 수신할 파일의 파일 디스크립터
// iov:     구조체 iovec배열의 주소 값
// iovcnt:  iov 배열의 길이정보

struct iovec {
    void *iov_base; // 버퍼의 주소 정보
    size_t iov_len; // 버퍼의 크기 정보
}
