#include <stdio.h>

FILE *fdopen(int fildes, const char* mode);
// 성공 시 변환된 FILE 구조체 포인터, 실패 시 NULL 반환

// fildes:  변환할 파일 디스크립터를 인자로 전달
// mode:    생성할 FILE 구조체 포인터의 모드 정보 전달

int fileno(FILE *stream);
// 성공 시 변환된 파일 디스크립터, 실패 시 -1 반환 
