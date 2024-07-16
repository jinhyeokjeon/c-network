#include <sys/socket.h>

int getsockopt(int sock, int level, int optname, void *optval, socklen_t *optlen);
// 성공 시 0, 실패 시 -1 반환

// sock:	옵션확인을 위한 소켓의 파일 디스크립터
// level:	확인할 옵션의 프로토콜 레벨
// optname:	확인할 옵션의 이름
// optval:	확인결과의 저장을 위한 버퍼의 주소 값
// optlen:	optval로 전달된 주소 값의 버퍼크기를 담고 있는 변수의 주소 값
//          함수 호출 완료 시 네 번째 인자를 통해 반환된 옵션정보의 크기가 바이트단위로 계산되어 저장

int setsockopt(int sock, int level, int optname, const void *optval, socklen_t optlen);
// 성공 시 0, 실패 시 -1 반환

// sock:	옵션변경을 위한 소켓의 파일 디스크립터
// level:	변경할  옵션의 프로토콜 레벨
// optname:	변경할 옵션의 이름
// optval:	변경할 옵션정보를 저장한  버퍼의 주소 값
// optlen:	optval로 전달된 옵션정보의 바이트단위 크기

// level, optname ---> p.200
