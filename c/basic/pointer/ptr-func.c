#include "ptr-head.h"

void Pointer01() {
    int a = 10;
    int * p;
    int * q;

    p = &a;
    //q = &a;
    q = p;

    printf("&p:%p %ld\n", &p, sizeof(p));
    printf("p:%p &a:%p\n", p, &a);
    printf("%d %d\n", a, *p);

    printf("\n\n&q:%p %ld\n", &q, sizeof(q));
    printf("%p %d\n", q, *q);
}

void Pointer02() {
    double a;
    double * p;
    p = &a;

    printf("%ld %ld %p\n", sizeof(double), sizeof(p), p);
}

void Pointer03() {
    int a = 10, * p;
    double b = 3, * q;

    p = &a;
    q = &b;

    printf("%p %p\n", p, p+2);
    printf("%p %p\n", q, q+2);
}

void Pointer04() {
    int a[5] = {4, 8, 1, 2, 7};
    int *p, *q;

    p = a; //&a[0];
    q = &a[3];

    printf("%p %p\n", p, q);
    printf("%d %d\n", *p, *q);
    printf("%ld\n", q-p);
}

void Pointer05() {
    int a[5] = {4, 8, 1, 2, 7};
    int *p = NULL, *q;

    printf("%d %p\n", p, p);
    p = a; //&a[0];

    printf("%p %d\n", p, *p);

    q = p++;

    printf("%p %d\n",p, *p);
    printf("%p %d\n",q, *q);
}

#define N 5

void Pointer06() {
    int a[N];
    int *p, i;

    p = a;//int *p = a;
    for (i = 0; i < N; i++)
        scanf("%d", p++);//&a[i]

    p = a;
    for (i = 0; i < N; i++)  {
        printf("%d ", *p);
        p++;
    }
    puts("");
}

void Pointer07() {
    int a[N];
    int *p, i;

    p = a;//int *p = a;
    for (i = 0; i < N; i++)
        scanf("%d", p++);//&a[i]

    p = a;
    for (i = 0; i < N; i++)  {
        printf("%d ", *p++);
    }
    puts("");
}

void Pointer08() {
    int a[] = {1, 6, 9, 12, 61, 12, 21};
    int *p, i, n;

    p = a;
    n = sizeof(a) / sizeof(int);

    printf("%p %p %p\n", a, a+1, a+2);

    for (i = 0; i < n; i++)
        printf("%d %d %d %d\n", a[i], *(p+i), *(a+i), p[i]);
    puts("");

    p++;

    printf("%d\n", p[1]);//*(p+1)
}

void Pointer09() {
    int a[] = {1, 6, 9, 12, 61, 12, 21};
    int *p, *q, n, t;

    n = sizeof(a) / sizeof(int);

    p = a;
    q = &a[n-1];

    while (p < q) {
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }

    for (t = 0; t < n; t++)
        printf("%d ", a[t]);
    puts("");
}

void Pointer10() {
    int a[3][2] = {{1, 6}, {9, 12}, {61, 12}};
    int * p, i, n;

    n = sizeof(a) / sizeof(int);

    p = a[0]; //&a[0][0];
    printf("%p %p\n", p, p+1);
    printf("%p %p\n", a, a+1);

    for (i = 0; i < n; i++)
        printf("%d ", *(p+i));
    puts("");
}

void Pointer11() {
    int a[3][2] = {{1, 6}, {9, 12}, {61, 12}};
    int * p, i, n;

    n = sizeof(a) / sizeof(int);

    //a[1]++;
    //printf("%d\n", sizeof(a[1]));

    p = a[0]; //&a[0][0];
    printf("%p %p\n", p, p+1);
    printf("%p %p\n", a, a+1);

    for (i = 0; i < n; i++)
        printf("%d ", *(p+i));
    puts("");
}

void Pointer12() {
    int a[3][2] = {{1, 6}, {9, 12}, {61, 12}};
    int * p, i, n;

    n = sizeof(a) / sizeof(int);

    printf("%p %p\n", a, a+1);
    //printf("%p %p\n", a[0], a[0]+1);
    printf("%p %p\n", *a, *a+1);
}

void Pointer13() {
    int a[3][2] = {{1, 6}, {9, 12}, {61, 12}};
    int (*p)[2], i, j;

    p = a;

    printf("%p %p\n", a, a+1);
    printf("%p %p\n", p, p+1);

    //printf("%d, %d, %d, %d\n", a[1][1], p[1][1], *(*(a + 1)+1), *(*(p + 1) + 1));
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++)
            printf("%d, %d, %d, %d ", a[i][j], p[i][j], *(*(a + i)+j), *(*(p + i) + j));
        puts("");
    }
}