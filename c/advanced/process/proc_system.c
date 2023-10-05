#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * system - 执行命令
 * int system(const char *command);
 * 1. system会调用fork创建子进程，子进程调用exec执行命令
 * 2. 父进程阻塞等待子进程结束
 * 3. system返回子进程的退出状态码
 * 4. system返回-1表示执行失败
 */

/*
 * execl 示例
 * 执行ls命令，显示/etc目录下所有文件的详细信息
 */
int main(int argc, char *argv[])
{
    if (system("ls -l -a /etc") < 0) {
        perror("execlp");
        return -1;
    }
    return 0;
}
