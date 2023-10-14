#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig)
{
    if (sig == SIGINT) {
        printf("receive SIGINT signal: %d\n", sig);
        exit(0);
    } else if (sig == SIGQUIT) {
        printf("receive SIGQUIT signal: %d\n", sig);
        exit(0);
    } else if (sig == SIGTSTP) {
        printf("receive SIGTSTP signal: %d\n", sig);
        exit(0);
    }

}

int main(int argc, char *argv[])
{
    // 设置信号处理函数
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    signal(SIGTSTP, sig_handler);
    while (1) {
        /*printf("hello world\n");
        sleep(1);*/
        printf("pause\n");
        pause();
    }
    return 0;
}