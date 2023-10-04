#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if ((fp = fopen("test.txt", "w")) == NULL) {
        ferror(fp);
        return 0;
    }

    // 默认全缓冲，这里不会输出，存放在柳缓冲区
    fputc('h', fp);
    // 这里通过fflush强制刷新缓冲区，输出h
    fflush(fp);
    while (1);
    return 0;
}