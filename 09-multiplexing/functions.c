#include <sys/select.h>
#include <sys/time.h>

int select(int maxfd, fd_set *readset, fd_set *writeset, fd_set *exceptset, const struct timeval *timeout);
// 성공 시 0 이상, 실패 시 -1 반환
// 함수 호출 이후에는 변화가 발생한 파일 디스크립터에 해당하는 비트만 1로 남아있게 된다.
// 함수 호출 이후에는 timeout에 타임아웃이 발생하기 전까지 남은 시간으로 바뀐다.

// maxfd:       검사 대상이 되는 파일 디스크립터의 수
// readset:     fd_set형 변수에 '수신된 데이터의 존재여부'에 관심 있는 파일 디스크립터 등록 후 주소값 전달
// writeset:    fd_set형 변수에 '블로킹 없는 데이터 전송의 가능여부'에 관심 있는 파일 디스크립터 등록 후 주소값 전달
// exceptset:   fd_set형 변수에 '예외상황의 발생여부'에 관심이 있는 파일 디스크립터 등록 후 주소값 전달
// timeout:     select 함수호출 이후에 무한정 블로킹 상태에 빠지지 않도록 타임아웃 설정
// 오류-> -1, 타임아웃-> 0, 관심대상 등록 파일 디스크립터 변화 발생-> 변화 발생 파일 디스크립터 수

FD_ZERO(fd_set *fdset);
// fd_set형 변수의 모든 비트 0으로 초기화

FD_SET(int fd, fd_set *fdset);
// fdset으로 전달된 주소의 변수에 매개변수 fd로 전달된 파일디스크립터 정보 등록

FD_CLR(int fd, fd_set *fdset);
// fdset으로 전달된 주소의 변수에서 fd로 전달된 파일 디스크립터 정보 삭제

FD_ISSET(int fd, fd_set *fdset);
// fdset으로 전달된 주소의 변수에 매개변수 fd로 전달된 파일 디스크립터 정보가 있으면 양수 반환

struct timeval {
    long tv_sec;    // seconds;
    long tv_usec;   // microseconds;
}
