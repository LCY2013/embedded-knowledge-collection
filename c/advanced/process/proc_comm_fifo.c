#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "const_head.h"

/**
 * main - gcc -o proc_comm_fifo proc_comm_fifo.c
 * 进程A：循环从键盘输入并写入有名管道myfifo,输入quit时退出
 * 进程B：循环统计进程A每次写入myfifo的字符串长度
 * @param agec
 * @param argv
 * @return
 */
int main(int agec, char *argv[]) {
    // 创建有名管道
    if (mkfifo(FIFO_NAME, 0666) < 0) {
        perror(FIFO_NAME);
        exit(-1);
    }

    return 0;
}
