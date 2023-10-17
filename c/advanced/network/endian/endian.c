#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// 检测主机是大端序列还是小端序列
int main(int argc, char *argv[])
{
    /*int a = 0x12345678;
    char *p = (char *)&a;
    printf("%x\n", *p);
    if(*p == 0x12) {
        printf("大端序列\n");
    } else {
        printf("小端序列\n");
    }*/
    uint16_t HostByteOrder = 0x0102;
    uint16_t NetByteOrder = htons(HostByteOrder);
    if (HostByteOrder == NetByteOrder)
        printf("Big Endian\n");
    else
        printf("Little Endian\n");
    return 0;
}