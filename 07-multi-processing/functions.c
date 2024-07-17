#include <unistd.h>

pid_t fork(void);
// 성공 시 프로세스 ID, 실패 시 -1 반환 

#include <sys/wait.h>

pid_t wait(int *statloc);
// 성공 시 종료된 자식 프로세스의 ID, 실패 시 -1 반환
// 종료된 자식 프로세스가 있다면, 자식 프로세스가 종료되면서 전달한 값(exit 함수의 인자 값, main 함수의 return에 의한 반환 값)
// 이 매개변수로 전달된 주소의 변수에 저장된다

// WIFEXITED:   자식 프로세스가 정상 종료한 경우(exit 함수 호출 OR 메인 함수에서 return문을 통해 종료) 참을 반환한다
// WEXITSTATUS: 자식 프로세스의 전달 값을 반환

pid_t waitpid(pid_t pid, int *statloc, int options);
// 성공 시 종료된 자식 프로세스의 ID (또는 0), 실패 시 -1 반환

//pid:      종료를 확인하고자 하는 자식 프로세스의 ID 전달, 이를 대신해서 -1을 전달하면 wait 함수와 마찬가지로 임의의 자식 프로세스가 종료되기를 기다린다.
//statloc:  wait 함수와 동일
//options:  상수 WNOHANG을 인자로 전달하면, 종료된 자식 프로세스가 존재하지 않아도 블로킹 상태에 있지 않고, 0을 반환하면서 함수를 빠져나온다. 

#include <signal.h>

void (*signal(int signo, void (*func)(int)))(int);
// signo 시그널 발생 시 호출될 함수 등록
// 시그널 발생 시 호출되도록 이전에 등록된 함수의 포인터 반환

// 함수 이름:       signal
// 매개변수 선언:   int signo, void(*func)(int)
// 반환형:          매개변수형이 int이고, 반환형이 void인 함수 포인터

// SIGALRM:     alarm 함수호출을 통해서 등록된 시간이 된 상황
// SIGINT:      CTRL+C 가 입력된 상황
// SIGCHLD:     자식 프로세스가 종료된 상황

#include <unistd.h>
unsigned int alarm(unsigned int seconds);
// 0 또는 SIGALRM 시그널이 발생하기까지 남아있는 시간을 초 단위로 반환
// 양의 정수를 인자로 전달 -> 전달된 시간(초 단위)가 지나서 SIGALRM 시그널 발생
// SIGALRM 시그널 발생의 기본 동작은 프로세스 종료
// 0 인자로 전달 -> 시그널 발생 예약 취소
