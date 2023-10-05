#include <stdio.h>

/*
 * 共享库生成流程
 * 1. 编译源文件 gcc -c -fPIC hello.c bye.c -Wall . -fPIC 表示生成位置无关代码
 * 2. 生成共享库common gcc -shared -o libcommon.so.1 hello.o bye.o
 * 3. 为共享库文件创建链接文件 ln -s libcommon.so.1 libcommon.so ，符号链接文件命名规则 lib<库名>.so
 */

void hello(void)
{
    printf("Hello, world!\n");
    return;
}
