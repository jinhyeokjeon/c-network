#include <sys/socket.h>

ssize_t sendto(int sock, void *buff, size_t nbytes, int flags, struct sockaddr *to, socklen_t addrlen);
// 성공 시 전송된 바이트 수, 실패 시 -1 반환

// sendto 호출시까지 소켓에 주소정보가 할당되지 않았다면, 함수가 처음 호출되는 시점에 해당 소켓에 IP와 PORT번호가 자동으로 할당된다
// IP는 호스트의 IP로, PORT는 사용하지 않는 임의의 PORT번호로

// sock:	데이터 전송에 사용될 UDP 소켓의 파일 디스크립터
// buff:	전송할 데이터를 저장하고 있는 버퍼의 주소 값
// nbytes:	바이트 단위의 전송할 데이터 크기
// flags:	옵션 지정에 사용되는 매개변수, 지정할 옵션이 없다면 0
// to:		목적지 주소정보를 담고 있는 sockaddr 구조체 변수의 주소값
// addrlen:	매개변수 to로 전달된 주소 값의 구조체 변수 크기 전달

ssize_t recvfrom(int sock, void *buff, size_t nbytes, int flags, struct sockaddr *from, socklen_t *addrlen);
// 성공 시 수신한 바이트 수, 실패 시 -1 반환

// sock:	데이터 수신에 사용될 UDP 소켓의 파일 디스크립터
// buff:	데이터 수신에 사용될 버퍼의 주소 값
// nbytes:	수신할 최대 바이트 수
// flags:	옵션 지정에 사용되는 매개변수, 지정할 옵션이 없다면 0
// from:	발신지 정보를 채워 넣을 sockaddr 구조체 변수의 주소값
// addrlen:	매개변수 from으로 전달된 주소에 해당하는 구조체 변수의 크기정보를 담고 있는 변수의 주소값
