#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * 进程结束 - exit/_exit
 * 1. 进程结束后，操作系统回收进程占用的资源
 * 2. 进程结束后，进程的PCB被销毁
 * 3. 进程结束后，进程的父进程会收到SIGCHLD信号
 * 4. 进程结束后，进程的退出状态码会传递给父进程
 * 5. exit结束进程时，会刷新(流)缓冲区，_exit不会
 */

int main(int argc, char *argv[])
{
    printf("this process will exit");
    exit(0);
    //_exit(pid);
    printf("never be displayed");
    return 0;
}
