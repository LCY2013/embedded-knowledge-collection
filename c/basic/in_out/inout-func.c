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

void PrintOne() {
    int a = 254;
    char ch = 'A';
    char s[] = "lsdfsdf";
    float f = 567.89;

    printf("%d %o %x\n", a, a, a);
    printf("%c-%d\n", ch, ch);
    printf("%s\n", s);

    printf("%f-%c-%g\n", f, f, f);
}

void PrintTwo() {
    int a = 254;
    float f = 345.667;
    char ch = 'a';

    printf("%8d\n%2d\n", a, a);
    printf("%9f-%9.2f-%.3f\n", f, f, f);
    printf("ch=%5c\n", ch);
}

void PrintThree() {
    int a = 254;
    float f = 345.7;
    char ch = 'a';

    printf("%08d\n%0+8d\n", a, a);
    printf("%09f-%09.2f-%.3f\n", f, f, f);
    printf("ch=%5c\n", ch);
}

void PrintFour() {
    int a = 254;
    float f = 345.7;
    char ch = 'a';

    printf("%08d\n%0+8d\n", a, a);
    printf("%09f-%09.2f-%.3f\n", f, f, f);
    printf("ch=%5c\n", ch);
}