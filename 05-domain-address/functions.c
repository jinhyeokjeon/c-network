#include <netdb.h>

struct hostent *gethostbyname(const char *hostname);
// 성공 시 hostent 구조체 변수의 주소 값, 실패 시 NULL 포인터 반환

struct hostent *gethostbyaddr(const char *addr, socklen_t len, int family);
// 성공 시 hostent 구조체 변수의 주소 값, 실패 시 NULL 포인터 반환

// addr:	IP주소를 지니는 in_addr 구조체 변수의 포인터 전달. IPv4 이외의 다양한 정보를 전달받을 수 있도록 매개변수는 char형 포인터
// len:		첫 번째 인자로 전달된 주소정보의 길이, IPv4의 경우 4, IPv6의 경우 16 전달
// family:	주소체계 정보 전달. IPv4: AF_INET, IPv6: AF_INET6

struct hostent {
	char * h_name;		// official name
	char ** h_aliases;	// alias list
	int h_addrtype;		// host address type / IPv4: AF_INET
	int h_length;		// address length / IPv4: 4(Byte)
	char ** h_addr_list;// address list / void형 포인터가 더 잘어울리지만, void형 포인터가 표준화되기 이전에 정의되어 char형 포인터로 선언됨. / 참조의 대상이 일정하지 않은 경우
};

