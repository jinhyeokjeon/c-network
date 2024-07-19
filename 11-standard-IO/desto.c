#include <stdio.h>
#include <fcntl.h>

int main(void) {
    FILE *fp;
    int fd = open("data.dat", O_WRONLY | O_CREAT | O_TRUNC);

    fp = fdopen(fd, "w");
    fputs("Network C programming\n", fp);
    fclose(fp); // 이 경우 파일자체가 완전히 종료되므로 파일 디스크립터를 이용해서 또 다시 종료할 필요는 없다.
    return 0;
}
