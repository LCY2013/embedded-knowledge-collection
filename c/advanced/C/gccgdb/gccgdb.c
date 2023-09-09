#include <stdio.h>

/*
 * 编译：gcc -o gccgdb gccgdb.c
 * 查看更详细的信息：gcc -v -o gccgdb gccgdb.c
 *
 * 预处理(Pre-Processing)
 * gcc -E gccgdb.c -o gccgdb.i
 * 用wc命令，查看这两个阶段代码大小：
 *  wc gccgdb.c gccgdb.i
 *    23      62     466 gccgdb.c
 *   555    2108   24026 gccgdb.i
 *   578    2170   24492 total
 *
 * 编译(Compiling)
 *  gcc -S gccgdb.c -o gccgdb.s
 *
 * 汇编(Assembling)
 *  方法一，用gcc直接从C源代码中生成目标代码：
 *      gcc –c gccgdb.c –o gccgdb.o
 *	方法二，用汇编器从汇编代码生成目标代码：
 *		as gccgdb.s –o gccgdb.o
 *
 * 链接(Linking)
 *  将目标程序链接库资源，生成可执行程序
 *		gcc  gccgdb.s –o gccgdb
 *
 * GDB调试工具
 *
 * 首先使用gcc对test.c进行编译，注意一定要加上选项‘-g’
 * gcc -g gccgdb.c -o gccgdb
 * gdb gccgdb
 *
 * gdb 调试流程
 *  查看文件
 *      (gdb) l
 *  设置断点
 *      (gdb) b 6
 *  查看断点情况
 *      (gdb) info b
 *  运行代码
 *      (gdb) r
 *  查看变量
 *      (gdb) p n
 *  单步运行
 *      (gdb) n
 *      (gdb) s
 *  恢复程序运行
 *      (gdb) c
 *  帮助
 *      (gdb) help [command]
 * */
int main(void) {
    int i,j;
    j = 0;
    i = j + 1;
    printf("hello, world\n");
    printf("the result is %d\n", i);
    return 0;
}
