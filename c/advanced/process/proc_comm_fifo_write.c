#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "const_head.h"

/**
 * main - gcc -o proc_comm_fifo_write proc_comm_fifo_write.c
 * 进程A：循环从键盘输入并写入有名管道myfifo,输入quit时退出
 * 进程B：循环统计进程A每次写入myfifo的字符串长度
 * @param agec
 * @param argv
 * @return
 */
int main(int agec, char *argv[]) {
    char buf[N];
    int pfd;

    // 打开有名管道
    if ((pfd = open(FIFO_NAME, O_WRONLY)) < 0) {
        perror(FIFO_NAME);
        exit(-1);
    }

    while (1) {
        printf("Enter some text: ");
        fgets(buf, N, stdin);
        if (strncmp(buf, "quit", 4) == 0) {
            break;
        }
        write(pfd, buf, N);
    }

    // 关闭管道
    close(pfd);

    return 0;
}
