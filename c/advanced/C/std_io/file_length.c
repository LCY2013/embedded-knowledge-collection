#include <stdio.h>

/*
 * 定位流：ftell fseek rewind
 * 判断流是否出错和结束：ferror feof
 */

int main(int argc, char *argv[])
{
    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        ferror(fp);
        return -1;
    }

    // 1. 定位到文件末尾
    fseek(fp, 0, SEEK_END);
    // 2. 获取文件指针的位置
    int len = ftell(fp);
    // 输出
    printf("len: %d\n", len);
    return 0;
}