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

void CharPointerOne() {
    char ch = 'A';

    char * p;

    p = &ch;

    printf("%c %c\n", ch, *p);
}

void CharPointerTwo() {
    char ch1[] = "hello World!";
    char ch2[] = "hello World!";

    char * p;

    p = ch1;
    //ch1[0]---*(ch1+0)----p[0], *p
    if(isalpha(*p)) {
        if (isupper(*p))
            *p = tolower(*p);
        else
            *p = toupper(*p);
    }
    printf("%p %s\n", p, p);

    p = ch2;
    printf("%p %s\n",p, p);
}

void CharPointerThree() {
    char * p1 = "hello World!";
    char * p2 = "hello World!";

    *p1 -= 32;

    printf("&p1=%p %p %s\n", &p1, p1, p1);

    printf("&p2=%p %p %s\n", &p2, p2, p2);
}

void CharPointerFour() {
    char ch[50] = "welcome";
    char * p1 = "hello World!";

    strcpy(ch, p1);
    //strcpy(p1, ch);

    puts(ch);
    puts(p1);
}

void CharPointerFive() {
    char ch[100] = "welcome";
    char * p = "hello World!", * q;
    int i = 0;

    q = p;

    while (*(ch+i) != '\0')
        i++;

    while (*p != '\0') {
        *(ch+i) = *p;
        i++;
        p++;
    }
    *(ch+i) = *p;

    p = q;
    puts(ch);
    puts(p);
}

void PPointerOne() {
    int m = 10;
    int * p;

    //....   * q;
    int* * q;

    p = &m;

    q = &p;

    printf("%p %p\n", p,&m);
    printf("%p %p\n", q,&p);
    printf("%d %d %d\n", m, *p, **q);

    printf("%p %p\n", q, q + 1);
}

void PPointerTwo() {
    int a[] = {3, 6, 9};
    int * p[2] = {&a[0], &a[1]};//int * ---  p[0]  p[1]

    int ** q;

    q = &p[0];//p
    q = p;

    printf("%d %d\n", a[0], a[1]);
    printf("%d %d\n", *p[0], *p[1]);

    printf("%d %d %d\n", a[0], *p[0], **q);
    printf("%d %d %d\n", a[1], *p[1], **(q+1));
}

void PPointerThree() {
    //char * s1 = "apple";
    //char * s2 = "pear";
    char * s[] = {"apple", "pear", "potato"};
    char ** p;
    int i, n;

    i = 0;
    n = sizeof(s) / sizeof(char *);
    p = &s[0];//p = s;

    while (i < n){
        printf("%s %s\n", s[i], *(p + i));
        i++;
    }
}

void PointerArrOne() {
    int * p[3]; //int *     --   p[0] p[1] p[2]
    int a[] = {3, 6, 1, 9, 10};

    p[0] = a;
    p[1] = a + 1;
    p[2] = a + 3;

    printf("%d %d %d\n", a[0], a[1], a[3]);
    printf("%d %d %d\n", *(p[0]), *p[1], *p[2]);
}

void PointerArrTwo() {
    int a[2][3] = {{1, 4, 6}, {12, 9, 7}};//a----a[0]   a[1]

    int * p[2];


    p[0] = a[0];//&a[0][0]
    p[1] = a[1];//&a[1][0]

    printf("%d\n", a[0][1]);
    printf("%d\n", *(a[0]+1));
    printf("%d\n", *(p[0]+1));

    printf("%d\n", *(p[1]+2));
}

void PointerArrThree() {
    int a[2][3] = {{1, 4, 6}, {12, 9, 7}};//a----a[0]   a[1]
    int * p[2] = {a[0], a[1]};
    int i, j;

    // a[1][1] => *(a[1] + 1) => *(*(a + 1) + 1)

    //printf("%p %p\n", p[0], a[0]);
    //printf("%p %p\n", p[1], a[1]);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++)
            //printf("%d %d ", *(a[i] + j), *(p[i]+j));
            printf("%d %d ", *(*(a+i) + j), *(*(p +i)+j));
        puts("");
    }
}

void PointerArrFour() {
    int a[2][3] = {{1, 4, 6}, {12, 9, 7}};//a----a[0]   a[1]
    int * p[2] = {a[0], a[1]};
    int i, j, sum = 0;

    int *  * q;

    q = p;//&p[0]

    printf("total:%ld\n", sizeof(p));
    //printf("%p %p\n", p[0], a[0]);
    //printf("%p %p\n", p[1], a[1]);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++)
            sum += *(p[i]+j);
        //printf("%d %d ", *(a[i] + j), *(p[i]+j));
        //   printf("%d %d ", *(*(a+i) + j), *(*(p +i)+j));
        //puts("");
    }

    printf("sum=%d\n", sum);
}

void ConstOne() {
    const int m = 10;
    //m++; //error
}

void ConstTwo() {
    int m = 10;
    const int * p;
    int * const q = &m;
    const int * const r = &m;

    p = &m; //right

    //(*p)++; // error 不允许改*p内容的值
    //q = &m; // error 不允许改q的值
    *q = 20; //right

    //r++; // error
    //(*r)++; // error
}

void VoidPointerOne() {
    int m = 10;
    double n = 3.14;
    void * p, * q;

    p = &m; // (void *)&m;
    printf("%d %d\n", m, *(int *)p);
    printf("%p\n", p);
    p++;
    printf("%p\n", p);

    q = &n;//(void *)&n;
    printf("%.2lf %.2lf\n", n, *(double *)q);
    printf("%p\n", q);
    q++;
    printf("%p\n", q);
}

void VoidPointerTwo() {
    int a[] = {5, 9, 1, 6, 9, 10};
    int i, n;
    void * p;

    p = a;
    n = sizeof(a) / sizeof(int);
    for (i = 0; i < n; i++)
        printf("%d ", *((int *)p + i));
    puts("");
}

void VoidPointerThree() {
    int a[] = {5, 9, 1, 6, 9, 10};
    int i, n;
    void * q;
    int * p;

    q = a;
    p = (int *)q;
    n = sizeof(a) / sizeof(int);
    for (i = 0; i < n; i++)
        printf("%d ", *(p + i));
    puts("");
}

void Main(int argc, char *argv[]) {
    //const char * argv[] = {"./prt-exec.o", "192.168.1.110", "9999"};
    int i;

    printf("argc=%d\n", argc);

    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
}