#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig)
{
    printf("receive signal: %d\n", sig);
}

int main(int argc, char *argv[])
{
    // 缺省情况下，alarm函数会打印Alarm clock, 然后退出进程, 但是如果设置了定时器处理函数，就不会打印Alarm clock
    // 自定义定时器处理函数
    signal(SIGALRM, sig_handler);

    // alarm 经常用来实现超时检测
    alarm(2);
    pause();
    printf("pause return\n");  // 如果没有设置定时器处理函数，这句话不会打印
    return 0;
}