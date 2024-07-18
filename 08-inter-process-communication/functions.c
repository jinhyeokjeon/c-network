#include <unistd.h>

int pipe(int filedes[2]);
// 성공 시 0, 실패 시 -1 반환

// filedes[0]: 파이프로부터 데이터를 수신하는데 사용되는 파일 디스크립터 저장
// filedes[1]: 파이프로 데이터를 전송하는데 사용되는 파일 디스크립터 저장
