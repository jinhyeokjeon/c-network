#include <sys/socket.h>

int shutdown(int sock, int howto);
// 성공 시 0, 실패 시 -1 반환
// shutdown으로 입출력 스트림을 종료하더라도 close를 호출하여 자원을 해제해야 한다.

// sock:  종료할 소켓의 파일 디스크립터
// howto: 종료방법에 대한 정보

// SHUT_RD, SHUT_WR, SHUT_RDWR
