#include <stdio.h>

//program file limit: 10237 + 3(stdin, stdout, stderr) = 10240
int main(int argc, char *argv[])
{
    int num = 0;
    FILE *fp;
    while ((fp = fopen("test.txt", "w+")) != NULL) {
         num++;
    }
    printf("program file limit: %d", num);
    return 0;
}