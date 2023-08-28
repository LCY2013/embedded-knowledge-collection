#include "inout-head.h"

void Getchar()
{
    int ch;

    printf(">");

    ch = getchar();

    putchar(ch);
    putchar('\n');
    printf("ch=%d\n", ch);
}