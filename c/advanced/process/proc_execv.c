#include <stdio.h>
#include <unistd.h>

/*
 * exec 函数族 execl/execlp/execle/execv/execvp/execve
 * 1. exec函数族用于执行其他程序
 * 2. exec函数族指定程序会替换当前进程的代码段、数据段、堆栈段等内容
 * 3. 实现让父子进程执行不同的程序
 *** 父进程调用fork()函数创建子进程，子进程调用exec函数族执行其他程序，父进程不受影响
 */

/*
 * execl 示例
 * 执行ls命令，显示/etc目录下所有文件的详细信息
 */
int main(int argc, char *argv[])
{
    char *arg[] = {"ls", "-l", "-a", "/etc", NULL};
    if (execv("/bin/ls", arg) < 0) {
        perror("execv");
        return -1;
    }

    /*if (execvp("ls", arg) < 0) {
        perror("execvp");
        return -1;
    }*/
    return 0;
}
