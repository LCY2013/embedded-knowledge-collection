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

void Gets()
{
    char s[N];

    scanf("%s", s);
    //gets(s);
    printf("s:%s", s);
    printf("***\n");
    puts("$$$");
    puts(s);
}