#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
	int serv_sock, clnt_sock;
	char message[30];
	int option, str_len;
	socklen_t optlen, clnt_addr_sz;
	struct sockaddr_in serv_addr, clnt_addr;

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	optlen = sizeof(option);
	option = TRUE;
	setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, (void*)&option, optlen);
	// Time-wait 상태에 있는 소켓에 할당되어 있는 PORT 번호를 새로 시작하는 소켓에 할당되게끔 한다.
	// 먼저 연결 종료를 요청한 소켓이 마지막으로 ACK 메시지를 보내고, 해당 메시지가 도착해야 소켓이 종료되어야
	// 하기 때문에, 메시지가 도착하지 않고 소멸되는 상황을 대비하여 종료되지 않고 TIME-WAIT 상태로 지속되다가 종료된다.
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	listen(serv_sock, 5);

	clnt_addr_sz = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_sz);
	
	while((str_len = read(clnt_sock, message, sizeof(message))) != 0) {
		write(clnt_sock, message, str_len);
		write(1, message, str_len);
	}

	close(clnt_sock);
	close(serv_sock);

	return 0;
}
