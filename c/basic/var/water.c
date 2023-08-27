#include <stdio.h>

#define W 3.0e-23
#define C 950

int main(int argc, char *argv[])
{
    float n;

    printf("input n:");
    scanf("%f", &n);

    n = n * C / W;
    printf("%f %e\n", n, n);

    return 0;
}