#include <sys/socket.h>

int socket(int domain, int type, int protocol);
// 소켓 생성 함수
// 성공 시 파일 디스크립터, 실패 시 -1 반환

// domain  : 소켓이 사용할 프로토콜 체계 정보 전달			-> PF_INET: IPv4, PF_INET6: IPv6
// type    : 소켓의 데이터 전송방식에 대한 정보 전달		-> SOCK_STREAM: TCP, SOCK_DGRAM: UDP
// protocol: 두 컴퓨터간 통신에 사용되는 프로토콜 정보 전달 -> 동일한 domain, type인 프로토콜 구분 용도 하나만 존재시 0 전달해도 됨

// TCP 소켓은 전송되는 데이터의 경계가 존재하지 않는다 즉 데이터 전송 함수의 호출횟수와 데이터 수신 함수의 호출횟수가 불일치 할 수 있다
// UDP 소켓은 전송되는 데이터의 경계가 존재한다 즉 데이터 전송 함수의 호출횟수와 데이터 수신 함수의 호출횟수가 일치한다

struct sockaddr {
	sa_family_t		sin_family;
	char			sa_data[14];
}

struct sockaddr_in {
	sa_family_t		sin_family;  // 주소체계					-> AF_INET: IPv4, AF_INET6: IPv6
	uint16_t		sin_port;    // 16 비트 TCP/UDP PORT 번호   -> 네트워크 바이트 순서로 PORT 번호 저장
	struct in_addr	sin_addr;    // 32 비트 IP 주소				-> 네트워크 바이트 순서로 IP 주소 저장
	char			sin_zero[8]; // 사용되지 않음				-> struct sockaddr과 사이즈를 맞추기 위해 존재
};
// struct sockaddr과 사이즈가 똑같은 IPv4 기반의 주소 표현을 위한 구조체

struct in_addr {
	in_addr_t	s_addr;	// 32비트 IPv4 인터넷 주소
}

// 바이트 순서의 변환(내 시스템 -> 빅 엔디안)
// h = host, n = network / l = long, s = short
unsigned short htons(unsigned short);
unsigned short ntohs(unsigned short);
unsigned long htonl(unsigned long);
unsigned long ntohl(unsigned long);

int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
// 소켓에 주소정보 할당
// 성공 시 0, 실패 시 -1 반환

// sockfd:	주소 정보를 할당할 소켓의 파일 디스크립터
// myaddr:	할당하고자 하는 주소정보를 지니는 구조체 변수의 주소 값
// addrlen:	두 번째 인자로 전달된 구조체 변수의 길이정보

int listen(int sock, int backlog);
// 소켓을 연결요청 가능한 상태가 되도록 하는 함수
// 성공 시 0, 실패 시 -1 반환

// sockfd: 연결요청 대기상태에 두고자 하는 소켓의 파일 디스크립터
// backlog: 연결요청 대기 큐의 크기정보

int accept(int sock, struct sockaddr *addr, socklen_t *addrlen);
// 연결요청 대기 큐에 존재하던 연결요청 하나를 꺼내서 연결 요청 수락
// 성공 시 생성된 소켓의 파일 디스크립터, 실패 시 -1 반환

// sock: 서버 소켓의 파일 디스크립터
// addr: 연결요청 한 클라이언트의 주소 정보를 담을 변수의 주소 값
// 매개변수 addr에 전달 된 주소의 변수 크기 바이트 단위로 전달. 변수에 저장한 후 변수의 주솟값 전달
// 함수호출이 완료되면 클라이언트의 주소정보 길이가 바이트단위로 계산되어 채워짐

// 생성된 소켓의 로컬 IP 주소와 로컬 포트번호는 서버 소켓에 바인딩된 IP 주소와 포트 번호와 동일
// 생성된 소켓의 원격 IP 주소와 원격 포트번호는 연결을 요청한 클라이언트의 IP 주소와 포트번호

int connect(int sock, struct sockaddr *serv_addr, socklen_t addrlen);
// 연결 요청 함수
// 성공 시 0, 실패 시 -1 반환

// 함수호출 시 소켓에 주소정보가 할당되지 않았다면 자동으로 소켓에 로컬 IP 주소와 로컬 포트번호가 할당되므로, 명시적으로 bind 함수를 호출할 필요가 없다
// IP는 호스트의 IP로, PORT는 임의의 사용하지 않는 PORT번호로 할당된다.

// sock:		클라이언트 소켓의 파일 디스크립터
// servaddr:	연결요청 할 서버의 주소정보를 담은 변수의 주소 값 전달
// addrlen:		두 번째 매개변수 servaddr에 전달된 주소의 변수 크기를 바이트 단위로 전달 

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

ssize_t write(int fd, const void *buf, size_t nbytes);
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

#include <arpa/inet.h>

// 네트워크 바이트 순서는 빅 엔디안 방식으로 통일

in_addr_t inet_addr(const char *string);
// 성공 시 빅 엔디안으로 변환된 32비트 정수 값, 실패 시 INADDR_NONE 반환
// 점이 찍힌 십진수 표현 방식 -> 네트워크 바이트 순서의 32비트 정수 변환

int inet_aton(const char *string, struct in_addr *addr);
// 성공 시 1, 실패 시 0 반환 
// inet_addr과 기능상으로 동일하다 다만 결과 값을 struct in_addr에 저장해준다

char *inet_ntoa(struct in_addr adr);
// 성공 시 변환된 문자열의 주소 값, 실패 시 -1 반환
// 반환된 문자열의 주소 값은 함수가 재호출되기 전까지만 유효하다

INADDR_ANY
// struct sockaddr_in addr; addrsin_addrs_addr = htonl(INADDR_ANY);
// 소켓 주소를 이렇게 초기화할 경우 소켓이 동작하는 컴퓨터의 IP주소가 자동으로 할당된다
