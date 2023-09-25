#include <stdio.h>

int main(int argc, char *argv[])
{
    int ch;
    ch = fgetc(stdin);
    printf("%c\n", ch);
    return 0;
}