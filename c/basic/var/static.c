#include <stdio.h>

int global_a;

void fun()
{
    int i;

    for (i = 0; i < 5; i++) {
        static int a;
        a++;
        global_a++;
        printf("a=%d global_a=%d\n", a, global_a);
    }
}

int main(int argc, char *argv[])
{
    fun();
    fun();
    fun();
    return 0;
}
