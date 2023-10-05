#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * 进程返回值和结束方式
 * 1. 子进程通过exit/_exit/return返回某个值(0-255)
 * 2. 父进程通过wait(&status)获取
 *  - WIFEXITED(status)  子进程正常结束
 *  - WEXITSTATUS(status)  获取子进程返回值
 *  - WIFSIGNALED(status)  子进程异常结束
 *  - WTERMSIG(status)  获取子进程异常结束信号编号
 *  - WIFSTOPPED(status)  子进程是否处于暂停状态
 *  - WSTOPSIG(status)  获取子进程暂停信号编号
 *
 * 进程回收 - waitpid
 * pid_t waitpid(pid_t pid, int *status, int options);
 * 1. 成功时返回回收的子进程ID或0，失败时返回EOF
 * 2. pid可用于指定回收某个子进程，pid=-1表示回收任意子进程
 * 3. status 指定保存子进程返回值和结束方式的地址
 * 4. options 用于指定回收方式， 0表示阻塞回收，WNOHANG表示非阻塞回收
 */

int main(int argc, char *argv[])
{
    int status;
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        sleep(1);
        printf("child pid = %d\n", getpid());
        exit(2);
    } else {
        printf("parent pid = %d\n", getpid());
        pid = wait(&status);
        printf("child pid = %d, status = %x\n", pid, status);
    }
    return 0;
}

