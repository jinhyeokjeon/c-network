#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
	int tcp_sock, udp_sock;
	char sock_type;
	socklen_t optlen;

	tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
	udp_sock = socket(PF_INET, SOCK_DGRAM, 0);
	printf("SOCK_STREAM: %d\n", SOCK_STREAM);
	printf("SOCK_DGRAM: %d\n", SOCK_DGRAM);

	optlen = sizeof(sock_type);
	getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &optlen);
	printf("Socket type one: %d, len: %d\n", sock_type, optlen);
	
	optlen = sizeof(sock_type);
	getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &optlen);
	printf("Socket type two: %d, len %d\n", sock_type, optlen);

	return 0;
}
