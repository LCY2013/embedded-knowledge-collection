#include <stdio.h>
#include <fcntl.h>
// 以只写方式打开文件test.txt, 如果文件不存在则创建，如果文件存在则清空文件内容。

int main(int argc, char *argv[])
{
    int fd;

    if ((fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0) {
        perror("open");
        return -1;
    }
    return 0;
}
