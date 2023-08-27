#include <stdio.h>

void func()
{
    auto int a = 1, i;
    for (i = 0; i < 5; i++) {
        a++;
        printf("a=%d\n", a);
    }
}

int main(int argc, char *argv[])
{
    func();
    //printf("a=%d\n", a);

    /*
    int i;

    for (i = 0; i < 5; i++) {
        auto int a = 1;
        a++;
        printf("a=%d\n", a);
    }
    //printf("a=%d\n", a);
    */
    return 0;
}