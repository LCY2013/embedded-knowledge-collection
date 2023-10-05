#include <stdio.h>
#include "common.h"

/*
 * 链接共享库 gcc -o test test.c -L. -lcommon
 * 1. 编译源文件 gcc -c test.c -Wall
 * 2. 链接共享库 gcc -o test test.o -L. -lcommon
 *
 * 如果出现了 dyld[29243]: Library not loaded: libcommon.so.1则说明系统找不到共享库，需要将共享库所在目录添加到环境变量中
 * 方法如下：
 * 1、export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
 * 2、将共享库所在目录添加到/etc/ld.so.conf文件（*.conf）中，然后执行ldconfig
 *   比如：echo "/home/linux/io/lib/share" >> /etc/ld.so.conf/my_share.conf
 *   再执行 ldconfig -v -f /etc/ld.so.conf/my_share.conf
 * 3、把库拷贝到/usr/lib和/lib目录下(不建议)
 */


int main(int argc, char *argv[])
{
    hello();
    bye();
    return 0;
}
