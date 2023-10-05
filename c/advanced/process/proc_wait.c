#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * 进程回收 - wait
 * pid_t wait(int *status);
 * 1. 成功时返回回收的子进程ID，失败时返回EOF
 * 2. 若子进程尚未结束，则父进程阻塞等待
 * 3. 若子进程已结束，则立即返回
 * 4. 若有多个子进程同时结束，则随机回收一个，那个先结束就先回收那个
 * 5. status 指定保存子进程返回值和结束方式的地址
 * 6. status为NULL表示直接释放子进程PCB，不关心返回值和结束方式
 */

/*
 * wait示例
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
