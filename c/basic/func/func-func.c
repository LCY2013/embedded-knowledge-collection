#include "func-head.h"

double power01(double x, int n)
{
    double r = 1;
    int i;

    for (i = 1; i <= n; i++)
        r *= x;

    return r;
}

void Func01() {
    double x = 2, ret;
    int n = 3;

    ret = power01(x, n);

    printf("%lf %d = %lf\n", x, n, ret);
}

double x = 2;
int n = 3;
double power02()
{
    double r = 1;
    int i;

    for (i = 1; i <= n; i++)
        r *= x;

    return r;
}

void Func02() {
//        double x = 2;
//        int n = 3;
    double ret;

    ret = power02();

    printf("%lf %d = %lf\n", x, n, ret);
}

double power03(double a, int b) {
    double r = 1;
    int i;

    printf("&a=%p &b=%p\n", &a, &b);

    for (i = 1; i <= b; i++)
        r *= a;
}

void Func03() {
    double x = 2;
    int n = 3;
    double ret;

    printf("&x=%p &n=%p\n", &x, &n);

    ret = power03(x, n);

    printf("%lf %d = %lf\n", x, n, ret);
}

//int x = a; int y = b;
void  swap04(int x, int y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

void Func04() {
    int a = 10;
    int b = 20;

    printf("before:%d %d\n", a, b);

    swap04(a, b);

    printf("after:%d %d\n", a, b);
}

//int * x = &a; int *y = &b;
void  swap05(int * x, int * y)
{
    int t;
    t = *x;//a
    *x = *y;
    *y = t;
}

void Func05() {
    int a = 10;
    int b = 20;

    printf("before:%d %d\n", a, b);

    swap05(&a, &b);

    printf("after:%d %d\n", a, b);
}

int str_fun06(const char * p) //char * p = s;
{
    int num = 0;
    while (*p != '\0') {//while (*p)
        if (*p <= 'z' && *p >= 'a')
            num++;
        p++;
    }
    return num;
}

void Func06() {
    char s[] = "welcome2017Beijing";
    int n;

    n = str_fun06(s);
    printf("n=%d\n", n);
}

int str_fun07(char * p) //char * p = s;
{
    int num = 0;
    while (*p != '\0') {//while (*p)
        if (*p <= 'z' && *p >= 'a') {
            num++;
            *p -= ' ';
        }
        p++;
    }
    return num;
}

void Func07() {
    char s[] = "welcome2017Beijing";
    int n;

    n = str_fun07(s);
    printf("n=%d %s\n", n, s);
}

int array_sum08(int data[], int n) // int data[] = a;error  int * data = a;
{
    //int n = sizeof(a)/sizeof(int);
    int ret = 0;
    int i;

    for (i = 0; i < n;i++) {
        printf("%d\n", data[i]);
        ret += data[i];
    }

    return ret;
}

void Func08() {
    int a[] = {5, 9, 10, 3, 10};
    int sum = 0;

    sum = array_sum08(a, sizeof(a)/sizeof(int));

    printf("sum=%d\n", sum);
}

int array_sum09(int * data, int n) //int * data = a;
{//int n = sizeof(a)/sizeof(int);
    int ret = 0;
    int i;

    for (i = 0; i < n;i++) {
        printf("%d\n", data[i]);
        ret += data[i];
    }

    return ret;
}

void Func09() {
    int a[] = {5, 9, 10, 3, 10};
    int sum = 0;

    sum = array_sum09(a, sizeof(a)/sizeof(int));

    printf("sum=%d\n", sum);
}

void del_space10(char * s1)
{
    char * s2;

    s2 = s1;

    while (*s1) {
        if (*s1 == ' '){
            s1++;
        }
        else {
            *s2 = *s1;
            s1++;
            s2++;
        }
    }
    *s2 = '\0';
}

void Func10() {
    char s[] = "   h  a   sdf g  ";

    puts(s);
    del_space10(s);
    puts(s);
}

double power(double x, int n)
{
    double r = 1;
    int i;

    for (i = 1; i <= n; i++)
        r *= x;

    return r;
}

void Power01() {
    double x, ret;
    int n;

    printf("input:");
    scanf("%lf%d", &x, &n);

    ret = power(x, n);

    printf("%lf %d = %lf\n", x, n, ret);
}

void Power02() {
    double x, ret;
    int n;

    printf("input:");
    scanf("%lf%d", &x, &n);

    ret = power(x, n);

    printf("%lf %d = %lf\n", x, n, ret);
}

