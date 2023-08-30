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

void ScanfOne() {
    int ch, n;
    long m;

    printf(">");

    //scanf("please input:%x", &ch);

    n = scanf("%x%ld", &ch, &m);

    printf("%d %d %ld\n", n, ch, m);
}

void ScanfTwo() {
    int y, m, d;

    printf(">");
    //scanf("%d%d%d", &y, &m, &d);
    scanf("%4d%2d%2d", &y, &m, &d);

    printf("%d:%d:%d\n", y, m, d);
}

void ScanfThree() {
    char y, m, d;

    printf(">");
    //scanf("%d%d%d", &y, &m, &d);
    scanf("%c%c%c", &y, &m, &d);

    printf("%d:%d:%d", y, m, d);
}

void ScanfFour() {
    int a;
    char x;

    printf(">");
    scanf("%d", &a);
    getchar();
    scanf("%c", &x);

    printf("%d:%c:%d\n", a, x, x);
    printf("%d\n", '\n');
}

void ScanfFive() {
    int a;
    char x;

    printf(">");
    scanf("%d", &a);
    //getchar();
    //scanf(" %c", &x);
    scanf("%*c%c", &x);

    printf("%d:%c:%d\n", a, x, x);

    printf("%d\n", '\n');
}

void Putchar() {
    int a = 65;
    char ch = 'B';

    putchar(a);
    putchar('\n');
    putchar(ch);
}