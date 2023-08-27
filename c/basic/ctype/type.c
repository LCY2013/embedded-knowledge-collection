#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    int a = 2, b = 3;
    float c = 3.14;
    int sum;

    sum = (int)(a + b + c);
    printf("%d\n", sum);

    return 0;
}