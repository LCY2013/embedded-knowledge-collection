#include <stdio.h>
#include <string.h>

#define N 6

int main(int argc, char *argv[])
{
    // 默认输出到标准输出
    //puts("hello world");
    FILE *fp;

    if ((fp = fopen(argv[1], "r+")) == NULL) {
        perror("fopen");
        return -1;
    }

    //统计一个文本文件包含多少行？
    // fgetc? 效率低
    // fgets? 如何判断读取了一行？
    char buf[N];
    int row = 0;
    while (fgets(buf, N, fp) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            row++;
        }
    }
    row++;
    printf("row: %d\n", row);
    return 0;
}