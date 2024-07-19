#include <unistd.h>

int dup(int fildes);
int dup2(int fildes, int fildes2);
// 성공 시 복사된 파일 디스크립터, 실패 시 -1 반환

// fildes:  복사할 파일 디스크립터 전달
// fildes2: 명시적으로 지정할 파일 디스크립터의 정수 값 전달
