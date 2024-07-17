#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) {
    if(sig == SIGALRM)
        puts("Time out!");
    alarm(2);
}
void keycontrol(int sig) {
    if(sig == SIGINT)
        puts("CTRL+C pressed");
}

int main() {
    int i;
    signal(SIGALRM, timeout);
    signal(SIGINT, keycontrol);
    alarm(2);
    for(i = 0; i < 3; i++) {
        puts("wait...");
        sleep(100);
        // 시그널 발생 시, 시그널 핸들러 호출을 위해 블로킹 상태에 있던 프로세스 깨어남
    }

    return 0;
}
