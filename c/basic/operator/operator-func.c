#include "operator-head.h"

void ope()
{
    int a = 15, b = 8, c;

    c = a + b;
    printf("c = %d\n", c);

    c = a - b;
    printf("c = %d\n", c);

    c = a * b;
    printf("c = %d\n", c);

    c = a / b;
    printf("c = %d\n", c);

    c = a % b;
    printf("c = %d\n", c);

    float d = 10.1, e = 8, f = 0;
    //f = d % e;
    //printf("c = %f\n", f);
    printf("%f, %f, %f\n", d, e, f);
}

void cmp()
{
    int a = 8, b = 7, c = 0;

    //if ((a - 1) <= b && b++ && a++)
    if ((a - 1) < b && b++ && a++)
        printf("true:%d %d %d\n", a, b, c);
    else
        printf("false:%d %d %d\n", a, b, c);
}

void mikiOperator()
{
    int x = 70, y = 10;

    //y = x++ > 70 ? x + y : 5;
    y = ++x > 70 ? x + y : 5;

    printf("x=%d y = %d\n", x, y);
}

void multiSegment()
{
    int x = 10, y = 3, z, a;

    z = (x += 5, y++, x + y);

    printf("x=%d y=%d z=%d\n", x, y, z);

    a = (x += y == z, y = x + 2, z = x + y + x > 0);

    printf("x=%d y = %d z=%d a=%d\n", x, y, z, a);
}

void priority()
{
    int x = 1, y = 0, z = 0;

    //if (x++ && y++ || ++z)
    if ((!(x + 1>0) && y++) || ++z)
        printf("true:%d %d %d\n", x, y, z);
    else
        printf("false:%d %d %d\n", x, y, z);
}

void sizeOf()
{
    int a = 5;
    long b = 3;
    long long c = 9;

    printf("%lu %lu %lu\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%lu %lu %lu\n", sizeof(int), sizeof(long), sizeof(long long));
}

void macroIf()
{
    int x = 15, y = 5, z;

#if 0
    y = ++x;
    printf("x=%d y=%d\n", x, y);

    y = ++x;
    printf("x=%d y=%d\n", x, y);
#endif

    z = ++x + y++;
    printf("x=%d y=%d z=%d\n", x, y, z);
}

