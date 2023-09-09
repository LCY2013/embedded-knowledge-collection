#include <stdio.h>
#include <math.h>

#define N 10
#define _DEBUG_ 0

int main(int argc, char *argv[]) {
    double m = 615, n;
    m += N;
    n = sqrt(m);
#if _DEBUG_
    printf("debug:m=%lf, n=%lf\n", m,n);
#else
    printf("release:m=%lf, n=%lf\n", m,n);
#endif
}
