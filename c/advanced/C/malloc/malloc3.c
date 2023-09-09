#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    //char *p;//没有初始化

    char *p;
    char s[] = "wel";   // w e l \0
    p = s;

    strcpy(p,"welcome");  // welcome 超出数组字节数

    return 0;
}
