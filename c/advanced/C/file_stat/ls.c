#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

//vim ls.c +83

int main(int argc, char *argv[])
{
    struct stat buf;
    int n;
    struct tm *tp;

    if (argc < 2) {
        printf("Usage : %s <file>\n", argv[0]);
        return -1;
    }

    if ((n = lstat(argv[1], &buf)) < 0) {
        perror("lstat");
        return -1;
    }

    switch (buf.st_mode & S_IFMT) {
        case S_IFREG:
            printf("-");
            break;
        case S_IFDIR:
            printf("d");
            break;
        case S_IFCHR:
            printf("c");
            break;
        case S_IFBLK:
            printf("b");
            break;
        case S_IFIFO:
            printf("p");
            break;
        case S_IFLNK:
            printf("l");
            break;
        case S_IFSOCK:
            printf("s");
            break;
        case S_IFWHT:
            printf("w");
            break;
    }

    /*for (n = 8; n >= 0; n--) {
        if (buf.st_mode & (1 << n)) {
            switch (n % 3) {
                case 2:
                    printf("r");
                    break;
                case 1:
                    printf("w");
                    break;
                case 0:
                    printf("x");
                    break;
            }
        } else {
            printf("-");
        }
    }*/

    printf("%c%c%c%c%c%c%c%c%c",
            buf.st_mode & S_IRUSR ? 'r' : '-',
            buf.st_mode & S_IWUSR ? 'w' : '-',
            buf.st_mode & S_IXUSR ? 'x' : '-',
            buf.st_mode & S_IRGRP ? 'r' : '-',
            buf.st_mode & S_IWGRP ? 'w' : '-',
            buf.st_mode & S_IXGRP ? 'x' : '-',
            buf.st_mode & S_IROTH ? 'r' : '-',
            buf.st_mode & S_IWOTH ? 'w' : '-',
            buf.st_mode & S_IXOTH ? 'x' : '-');

    printf(" %lld", buf.st_size);
    tp = localtime(&buf.st_mtime);
    printf(" %d-%02d-%02d",
            tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday);
    printf(" %s\n", argv[1]);
    return 0;
}