#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return 0;
    }
    FILE *fp;
    int ch, count = 0;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }
    printf("total %d bytes\n", count);
    return 0;
}