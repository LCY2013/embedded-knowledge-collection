#include <stdio.h>

// 错误处理

int main(int argc, char *argv[])
{
    FILE *fp;

    if ((fp = fopen("test.txt", "r+")) == NULL) {
        perror("fopen");
        return -1;
    }
    return 0;
}