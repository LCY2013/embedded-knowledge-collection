#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // 默认输出到标准输出
    //puts("hello world");
    FILE *fp;
    char buf[] = "hello world";
    if ((fp = fopen(argv[1], "a")) == NULL) {
        perror("fopen");
        return -1;
    }

    fputs(buf, fp);
    return 0;
}