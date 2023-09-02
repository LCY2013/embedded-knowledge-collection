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

