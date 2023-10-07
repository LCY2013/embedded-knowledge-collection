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
 * 无名管道没有读端，会导致写端阻塞，直到管道缓冲区满，此时会产生SIGPIPE信号，导致进程退出。
 */
int main(void)
{
    pid_t pid;
    int fd[2], status;
    char buf[32];

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(-1);
    }

    close(fd[0]);

    if ((pid = fork()) < 0) { // 创建子进程错误
        perror("fork");
        exit(-1);
    } else if (pid == 0) { // 子进程写入一个无读端的pipe
        write(fd[1], buf, 32);
        exit(0);
    } else { // 父进程
        waitpid(pid, &status, 0);
        printf("sub process status: %x, %d\n", status, status); // status 为SIGPIPE信号
        //kill -l 查看退出的状态码
    }

    return 0;
}

