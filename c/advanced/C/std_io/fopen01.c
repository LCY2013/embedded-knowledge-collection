#include <stdio.h>

/**
 * 6种mode: r\rb r+\r+b w\wb w+\w+b a\ab a+\a+b
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    FILE *fp;
    if ((fp = fopen("test.txt", "r+")) == NULL) {
        printf("fopen error\n");
        return -1;
    }
    return 0;
}
