#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd, n, total = 0;
    char buf[64];

    if (argc < 2) {
        printf("Usage : %s <file>\n", argv[0]);
        return -1;
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        total += n;
    }

    close(fd);

    printf("total %d bytes\n", total);
    return 0;
}