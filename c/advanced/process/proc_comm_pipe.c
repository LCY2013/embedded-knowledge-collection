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
 * 子进程1和子进程2分别往管道写入数据，父进程从管道读取数据。
 */
int main(void)
{
    pid_t pid1, pid2;
    int fd[2];
    char buf[32];

    if (pipe(fd) < 0) {
        perror("pipe");
        exit(-1);
    }

    if ((pid1 = fork()) < 0) { // 创建子进程1错误
        perror("fork");
        exit(-1);
    } else if (pid1 == 0) { // 子进程1
        close(fd[0]);
        strcpy(buf, "i`m process1");
        write(fd[1], buf, 32);
        exit(0);
    } else {
        if ((pid2 = fork()) < 0) { // 创建子进程2错误
            perror("fork");
            exit(-1);
        } else if (pid2 == 0) { // 子进程2
            close(fd[0]);
            sleep(1); // 等待子进程1写入数据(否则会被父进程读取)
            strcpy(buf, "i`m process2");
            write(fd[1], buf, 32);
            exit(0);
        } else { // 父进程
            close(fd[1]);
            read(fd[0], buf, 32);
            printf("%s\n", buf);
            read(fd[0], buf, 32);
            printf("%s\n", buf);
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
        }
    }
    return 0;
}

