#include <stdio.h>

#define N 6

int main(int argc, char *argv[])
{
    char buf[N];
    // gets 最多读取N-1个字符，最后一个是\0
    fgets(buf, N, stdin);
    printf("%s", buf);
    return 0;
}
