#include "pfunc-head.h"

int facOne(int n) {
    if (n == 0 || n == 1)
        return 1;

    return n * facOne(n - 1);
}

void DiguiOne() {
    int n;

    printf("input:");
    scanf("%d:", &n);

    printf("%d\n", facOne(n));
}

int fibTwo(int n) {
    if (n == 1 || n == 2)
        return 1;

    return fibTwo(n - 1) + fibTwo(n - 2);
}

void DiguiTwo() {
    int n = 1;

    while (n <= 10) {
        printf("%d  ", fibTwo(n));
        n++;
    }

    printf("\n");
}

char * errorGetString() {
    char str[20]; // error
    // static char str[20]; //right

    strcpy(str, "hello");

    return str;
}

void ErrorPfunc() {
    char *r;

    r = errorGetString();
    printf("---%s---\n", errorGetString());

    (*r)++;
    puts(r);
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mut(int a, int b) {
    return a * b;
}

void FunpOne() {
    int m = 10, n = 20;

    int (*p)(int, int);

    p = add;

    //printf("%d\n", add(m, n));
    printf("%d\n", (*p)(m, n));

    p = sub;
    printf("%d\n", (*p)(m, n));
}

void FunpTwo() {
    int m = 10, n = 20;

    int (* p[2])(int, int); //int * p[3]
    p[0] = add;
    //printf("%d\n", add(m, n));
    printf("%d\n", (*p[0])(m, n));

    p[1] = sub;
    printf("%d\n", (*p[1])(m, n));
}

char * mstrcat(char * dest, const char * src)
{
    char * r = dest;

    while (*dest++);

    dest--;

    while (*dest++ = *src++);

    return r;
    /*
    char * r = dest;

    while (*dest++);

    dest--;

    while (*src) {
            *dest++ = *src++;
    }

    *dest = '\0';

    return r;
    */
    /*
    char * r = dest;

    while (*dest) {
            dest++;
    }

    while (*src) {
            *dest = *src;
            dest++;
            src++;
    }

    *dest = '\0';

    return r;
    */
}

void Mstrcat() {
    //char * r;
    char dest[50] = "welcome";
    char src[] = "makeru";

    puts(mstrcat(dest, src));
    puts(dest);
}

char * itoa(int n)
{
    int r, i = 0, j;
    static char p[50];

    while (n) {
        r = n % 10;
        n /= 10;
        p[i] = r + '0';
        i++;
    }
    p[i] = '\0';

    j = i-1;
    i = 0;

    while (i < j) {
        r = p[i];
        p[i] = p[j];
        p[j] = r;
        i++;
        j--;
    }

    return p;
}

void Itoa() {
    int n;
    char * s;

    printf("input:");
    scanf("%d", &n);

    s = itoa(n);

    puts(s);
}

char * itoa1(char *p, int n)
{
    int r, i = 0, j;
    //static char p[50];

    while (n) {
        r = n % 10;
        n /= 10;
        p[i] = r + '0';
        i++;
    }
    p[i] = '\0';

    j = i-1;
    i = 0;

    while (i < j) {
        r = p[i];
        p[i] = p[j];
        p[j] = r;
        i++;
        j--;
    }

    return p;
}

void Itoa1() {
    int n;
    char  s[50], * r;

    printf("input:");
    scanf("%d", &n);

    r = itoa1(s, n);

    puts(r);
    puts(s);
}

int compare(const void * p, const void * q)
{
    return (*(int *)p - *(int *)q);

}

void Qsort() {
    int s[] = {89, 23, 10, 8, 7, 61}, n, i;

    n = sizeof(s)/sizeof(int);

    qsort(s, n, sizeof(int), compare);

    for (i = 0; i < n; i++)
        printf("%d ", s[i]);
    puts("");
}

#define N 1
#define _DEBUG_

void Test() {
    int m = 624;

    m += 1;

#ifdef _DEBUG_
    printf("%s %s, %d\n", __FILE__, __FUNCTION__, __LINE__);
#endif

    m = sqrt(m);

    printf("m=%d\n", m);
}