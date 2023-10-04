#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *dp;

    if (argc < 2) {
        printf("Usage : %s <directory>\n", argv[0]);
        return -1;
    }

    if ((dir = opendir(argv[1])) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((dp = readdir(dir)) != NULL) {
        printf("%s\n", dp->d_name);
    }

    closedir(dir);
    return 0;
}