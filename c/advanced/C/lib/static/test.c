#include <stdio.h>

/*
 * 链接静态库 gcc -o test test.c -L. -lhello
 * gcc 默认先找共享库libcommon.so），再找静态库，可以强行指定静态库 -static
 * 1. 编译源文件 gcc -c test.c -Wall
 * 2. 链接静态库 gcc -o test test.o -L. -lhello
 */

void hello(void);

int main(int argc, char *argv[])
{
    hello();
    return 0;
}
