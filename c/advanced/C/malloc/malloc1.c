#include <stdio.h>
#include <stdlib.h>

char * get_string()
{
    //char s[] = "welcome"; //(有警告)局部变量，放在栈上，函数结束自动销毁

    //static char s[] = "welcome";  //静态存储区，从分配开始，到程序结束才被回收。

    //char *s = "welcome";  //指针，字符串常量，不允许修改。

    char * s;

    s = (char *)malloc(10*sizeof(char));
    if(s == NULL)
    {
        printf("malloc failed\n");
        return 0;
    }
    printf("input:");
    scanf("%s",s);
    printf("%s\n",s);

    return s;          //要保证返回的地址能被主函数正常接收到
}

int main(int argc, const char *argv[])
{
    char *p;
    p = get_string();
    printf("%s\n",p);

    free(p);
    p = NULL;

    return 0;
}
