#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

/*
 * pipe() creates a pipe, a unidirectional data channel that can be used for
 * interprocess communication. The array pipefd is used to return two file
 * descriptors referring to the ends of the pipe. pipefd[0] refers to the read
 * end of the pipe. pipefd[1] refers to the write end of the pipe. Data written
 * to the write end of the pipe is buffered by the kernel until it is read from
 * the read end of the pipe. For further details, see pipe(7).
 *
 * 无名管道 - 示例
 * 计算无名管道大小
 */
int main(void)
{
    int count = 0, fd[2];
    char buf[1024];

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(-1);
    }

    while (1) {
        write(fd[1], buf, 1024);
        printf("count = %dk bytes\n", ++count);
    }

    return 0;
}

