#include "arr-head.h"

void ArrOne() {
    int a[2][3];
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++)
            printf("%p ", &a[i][j]);
        putchar('\n');
    }
}

void ArrTwo() {
    //int a[2][3] = {{1, 6, 9}, {2, 8, 5}}; 1
    //int a[2][3] = {{1, 6}, {2}};
    //int a[][3] = {{1, 6}};
    //int a[3][3] = {{1}, {2, 3}, {4}};
    int a[][3] = {{1}, {2, 3}, {4}};
    //int a[3][] = {{1}, {2, 3}, {4}};
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        putchar('\n');
    }
}

void ArrThree() {
    int a[10][10] = {{0}};
    int i, j;

    for (i = 0; i < 10; i++) {
        a[i][0] = 1;
        for (j = 1; j <= i; j++)
            a[i][j] = a[i-1][j-1] + a[i-1][j];
    }

    for (i = 0; i < 10; i++)  {
        for (j = 0; j <= i; j++)
            printf("%-8d ", a[i][j]);
        putchar('\n');
    }
}

void ArrFour() {
    //int i = 6, a[i];
    int a[6] = {1, 4, 5}, i, n;
    int b[] = {3, 4, 7, 8, 1, 0};

    n = sizeof(b) / sizeof(int);
    for (i = 0; i < n; i++)
        //printf("%p %d  ", &a[i], a[i]);
        printf("%p %d\n", &b[i], b[i]);

    //a = a + 1;
    printf("%p\n", a);
    printf("%ld\n", sizeof(a));
}

void Max() {
    int a[2][3] = {{2, 5, 8}, {21, 56, 9}};
    int i, j, row, column;

    row = column = 0;

    for (i = 0; i < 2; i++)  {
        for (j = 0; j < 3; j++) {
            if (a[row][column] < a[i][j]) {
                row = i;
                column = j;
            }
        }
    }

    for (i = 0; i < 2; i++)  {
        for (j = 0; j < 3; j++)
            printf("%5d ", a[i][j]);
        putchar('\n');
    }

    printf("max=%d %d %d\n", a[row][column], row, column);
}

void Sort() {
    int a[] = {3, 4, 17, 8, 31, 2, 9, 15}, n, i, j;
    int t;

    n = sizeof(a) / sizeof(int);

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (a[j] > a[j+1]){//0---
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }


    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    puts("");
}