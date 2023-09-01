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


