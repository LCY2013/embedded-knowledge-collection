#include <stdio.h>

/*
 * 静态库生成流程
 * 1. 编译源文件 gcc -c hello.c -Wall
 * 2. 生成静态库文件 ar crs libhello.a hello.o
 * 3. 查看库中符号信息 nm libhello.a
 */

void hello(void)
{
    printf("Hello, world!\n");
    return;
}