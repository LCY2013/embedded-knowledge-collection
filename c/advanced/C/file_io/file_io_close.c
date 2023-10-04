#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

// 关闭文件描述符

int main(int argc, char *argv[])
{
    int fd;
    if ((fd = open("test.txt", O_RDWR|O_CREAT|O_EXCL, 0666)) < 0) {
        if (errno == EEXIST) {
            printf("file exists\n");
        } else {
            perror("open");
            return -1;
        }
    }

    close(fd);
    return 0;
}