#include <stdio.h>

extern int global_a;
extern int global_b;

int main(int argc, char *argv[])
{
    printf("%d\n", global_a);
    printf("%d\n", global_b);

    return 0;
}