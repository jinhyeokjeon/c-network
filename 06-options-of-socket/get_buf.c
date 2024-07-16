#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
	int sock;
	int snd_buf, rcv_buf;
	socklen_t len;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	len = sizeof(snd_buf);
	getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void*)&snd_buf, &len);

	len = sizeof(rcv_buf);
	getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (void*)&rcv_buf, &len);

	printf("Input buffer size: %d\n", snd_buf);
	printf("Output buffer size: %d\n", rcv_buf);

	return 0;
}
