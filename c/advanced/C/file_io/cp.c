#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

// 利用文件io实现文件的复制

#define N 64

int main(int argc, char *argv[])
{
    int fds, fdt, n;
    char buf[N];

    if (argc < 3) {
        printf("Usage : %s <src> <dst>\n", argv[0]);
        return -1;
    }

    if ((fds = open(argv[1], O_RDONLY)) < 0) {
        fprintf(stderr, "open %s error : %s\n", argv[1], strerror(errno));
        return -1;
    }

    if ((fdt = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666)) < 0) {
        fprintf(stderr, "open %s error : %s\n", argv[2], strerror(errno));
        return -1;
    }

    while ((n = read(fds, buf, sizeof(buf))) > 0) {
        write(fdt, buf, n);
    }

    close(fds);
    close(fdt);

    return 0;
}