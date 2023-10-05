#include <stdio.h>
#include <unistd.h>

/*
 * 父子进程
 * pid_t fork(void);
 * 1. fork()函数调用一次，返回两次，子进程返回0，父进程返回子进程的pid
 * 2. 子进程继承父进程的数据段、堆栈段、代码段等内容
 * 3. 父子进程有独立的地址空间，各自的变量互不影响
 * 4. 父子进程的执行顺序不确定，由操作系统调度
 * 5. 若父进程先于子进程结束，子进程成为孤儿进程，由init进程接管，子进程变成后台进程
 * 6. 若子进程先于父进程结束，父进程调用wait()函数等待子进程结束，否则子进程成为僵尸进程
 */

int main(int argc, char *argv[])
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        printf("child process: my pid is %d\n", getpid());
    } else {
        printf("parent process: my pid is %d\n", getpid());
    }
    return 0;
}
