#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

/*
 * 守护进程
 * 1. 守护进程（Daemon）是Linux三种进程之一，另外两种是交互式进程和批处理进程。
 * 2. 守护进程是一种生存期较长的进程，通常在系统启动时运行，系统关闭时结束，通常独立于控制终端并且周期性地执行某种任务或等待处理某些发生的事件。
 * 3. Linux系统中大量使用，很多服务程序都是以守护进程运行，如httpd、sshd等。
 * 4. 守护进程的特点：
 *   1. 通常没有控制终端，与控制终端无关，不能被终端所控制
 *   2. 通常在后台运行
 *   3. 通常周期性地执行某种任务或者等待处理特定实践
 *
 * 守护进程 - 会话、控制终端
 * 1. Linux以会话（session）、进程组（process group）和控制终端（controlling terminal）为基础，来管理进程。
 * 2. 每个进程都属于一个进程组，每个进程组都有一个进程组ID，进程组中的每个进程都有一个进程ID。
 * 3. 会话是一个或多个进程组的集合，通常一个会话中只有一个进程组，该进程组为会话的首进程组。通常用户打开一个终端时，会话就会被系统创建。所有通过该终端打开的进程都属于该会话。
 * 4. 终端关闭时，会话就会结束，会话中的所有进程都会被终止。
 *
 * 守护进程创建
 * 1. 守护进程的创建步骤：
 *  1. 创建子进程，父进程退出
 *     if(fork() > 0) {
 *       exit(0);
 *     }
 *     // 子进程继续执行
 *     子进程变成了孤儿进程，被init进程收养
 *     子进程在后台运行
 *  2. 在子进程中创建新会话
 *      if(setsid() < 0) {
 *        exit(-1);
 *      }
 *      子进程成为新会话的首进程，会话组长
 *      子进程脱离原来的控制终端
 *  3. 改变当前工作目录
 *     chdir("/")
 *     守护进程一直在后台运行，其工作目录不能被卸载
 *     重新设定当前工作目录cwd
 *  4. 重设文件权限掩码
 *     if(umask(0) < 0) {
 *       exit(-1);
 *     }
 *     文件权限掩码设置为0，不会影响文件的权限
 *     只影响当前进程
 *  5. 关闭打开的文件描述符
 *      int i;
 *      for(i = 0; i < getdtablesize(); i++) {
 *        close(i);
 *      }
 *      关闭所有从父进程继承的打开文件描述符
 *      已脱离控制终端，父进程退出，stdin、stdout、stderr无法再使用都会被关闭
 *      重定向标准输入、输出、错误到/dev/null
 *  6. 执行守护进程核心工作
 *  7. 退出
 *  8. 守护进程的核心工作是在步骤6中执行的，通常是一个死循环，不断地执行某种任务或等待处理某些事件。
 *
 * 守护进程 - 例子
 * 创建守护进程，每隔1秒将系统时间写入文件time.log
 *
 */

int main(int argc, char *argv[])
{
    pid_t pid;
    FILE *fp;
    time_t t;
    int i;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(-1);
    } else if (pid > 0) {
        exit(0);
    }
    setsid();
    chdir("/tmp");
    umask(0);
    for (i = 0; i < getdtablesize(); i++) {
        close(i);
    }
    if ((fp = fopen("time.log", "a")) == NULL) {
        perror("fopen");
        exit(-1);
    }
    while (1) {
        time(&t);
        fprintf(fp, "%s", ctime(&t));
        fflush(fp);
        sleep(1);
    }
    return 0;
}