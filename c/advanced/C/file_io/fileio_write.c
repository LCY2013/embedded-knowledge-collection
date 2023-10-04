#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//将键盘输入的内容写入文件，直到输入quit退出

int main(int argc, char *argv[])
{
    int fd;
    char buf[20];

    if (argc < 2) {
        printf("Usage : %s <file>\n", argv[0]);
        return -1;
    }

    if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0) {
        perror("open");
        return -1;
    }

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (strncmp(buf, "quit", 4) == 0)
            break;
        write(fd, buf, strlen(buf));
    }

    close(fd);

    printf("write to file %s finish\n", argv[1]);

    return 0;
}