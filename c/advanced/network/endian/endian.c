#include <stdio.h>

// 检测主机是大端序列还是小端序列
int main(int argc, char *argv[])
{
    int a = 0x12345678;
    char *p = (char *)&a;
    if(*p == 0x12) {
        printf("大端序列\n");
    } else {
        printf("小端序列\n");
    }
    return 0;
}