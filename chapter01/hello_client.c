#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // inet_addr: "211.214.107.99"와 같이 점이 찍힌 10진수 문자열로 표현된 ip 주소를 네트워크 바이트 순서(빅 엔디안)로 정렬된 32비트 정수로 반환.
    // == inet_aton(argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // (클라이언트 소켓의 파일 디스크립터, 연결요청할 서버의 주소정보를 담은 변수의 주솟값, 두번째 매개변수에 전달된 주소의 변수 크기)
    // 서버에 의해 연결요청이 접수(연결요청 대기큐에 등록)되거나, 네트워크 단절 등 오류상황이 발생해서 연결요청이 중단된 경우에 함수가 반환된다.
    // connect 함수 호출 시 소켓에 나의 주소 즉 IP(호스트에 할당된 IP)와 PORT(임의로)가 할당된다. 따라서 클라이언트 프로그램을 구현할 때에는 명시적으로 bind 함수를 호출할 필요가 없다.
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error!");

    str_len = read(sock, message, sizeof(message)); // (수신 대상 파일 디스크립터, 수신할 데이터의 버퍼 주소값, 수신할 최대 바이트 수)
    if (str_len == -1)
        error_handling("read() error!");

    printf("Message from server : %s \n", message);
    close(sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}