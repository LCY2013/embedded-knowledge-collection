#include "loop-head.h"

void ForOne() {
    int i, sum;

    sum = 0;
    i = 1;
    for (;;) {//while(1)
        sum += i;
        i++;
        if ( i > 100)
            break;
    }

    printf("sum=%d\n", sum);
}

void ForTwo() {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4;j++)
            printf("i=%d j=%d\n", i, j);
        puts("");
    }
}

void ForThree() {
    int i, j;
    char ch = 'F';

    printf("please input char:");
    scanf("%c", &ch);

    for (i = 0; i <= ch - 'A' ; i++) {
        for(j = 0; j < i; j++)
            putchar('_');

        for(j = 0; j <= i; j++)
            putchar(ch-j);

        putchar('\n');
    }
}

void WhileOne() {
    int i = 1;
    int sum = 0;

    while (i <= 100) {
        sum += i;
        i++;
    }

    printf("1+2+...+%d=%d\n", i, sum);
}

void WhileTwo() {
    int n = 100;
    int a, b, c;//bai  shi ge 123

    while (n <= 999) {
        a = n / 100;
        b = n / 10 % 10;
        c = n % 10;

        //if (a*a*a + b*b*b + c*c*c == n)
        if (pow(a, 3) + pow(b, 3) + pow(c, 3) == n)
            printf("%d\n", n);
        n++;
    }
}

void DoWhile() {
    int i = 1;
    int sum = 0;

    do {
        sum += i;
        i++;
    }while (i <= 100);

    printf("1+2+...+%d=%d\n", i, sum);
}

void ContinueOne() {
    int n;

    for (n = 100; n <= 120; n++) {
        if (n % 3 == 0)
            //break;
            continue;
        printf("%d\n", n);
    }
}

#define PI 3.14

void ContinueTwo() {
    int n, tmp;
    int i;

    loop:
    printf("input n(>=3):");
    if (scanf("%d", &n) == 0 || n < 3) {
        printf("input error!\n");
        getchar();
        goto loop;
    }

    i = 2;
    tmp = sqrt(n);

    while( i <= tmp) {
        if (n % i == 0)
            break;
        i++;
    }
    if (i <= tmp)
        printf("%d not\n", n);
    else
        printf("%d yes\n", n);
}

int fun() {
    int r = 5;
    return r;
}

void ContinueThree() {
    int n, tmp;
    int i;
    int ch, ret;;

    ret = fun();
    printf("ret=%d\n", ret);

    while(1) {
        printf("input n(>=3):");
        if (scanf("%d", &n) == 0) {
            if ((ch = getchar()) == '#')
                return;// break;
            else if (n < 3) {
                continue;
            } else {
                printf("input error!\n");
                continue;
            }
        }

        i = 2;
        tmp = sqrt(n);

        while( i <= tmp) {
            if (n % i == 0)
                break;
            i++;
        }
        if (i <= tmp)
            printf("%d not\n", n);
        else
            printf("%d yes\n", n);

    }
}

void BreakOne() {
    int r, area;

    while(1) {
        for (r = 1; r <= 10; r++) {
            area = PI * r * r;
            if (area > 100)
                //break;
                return;
            printf("%d-%d\n", r, area);
        }
    }
}

void BreakTwo() {
    int n, tmp;
    int i;

    printf("input n(>=3):");
    scanf("%d", &n);

    i = 2;
    tmp = sqrt(n);

    while( i <= tmp) {
        if (n % i == 0)
            break;
        i++;
    }
    if (i <= tmp)
        printf("%d not\n", n);
    else
        printf("%d yes\n", n);
}

void Multiplication() {
    int i, j;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i ;j++)
            printf("%d*%d=%d\t", j, i, i * j );
        puts("");
    }
}
