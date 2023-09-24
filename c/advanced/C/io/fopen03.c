#include <stdio.h>
#include <string.h>
#include <errno.h>

// 错误处理

int main(int argc, char *argv[])
{
    FILE *fp;

    if ((fp = fopen("test.txt", "r+")) == NULL) {
        printf("fopen: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}