#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    if ((fp = fopen("test.txt", "r+")) == NULL) {
        printf("fopen error\n");
        return -1;
    }
    fclose(fp);
    return 0;
}