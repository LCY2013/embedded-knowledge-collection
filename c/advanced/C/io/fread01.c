#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen err");
        return -1;
    }

    int s[10];
    if (fread(s, sizeof(int), 10, fp)) {
        perror("fread");
        return -1;
    }
    return 0;
}