#include <stdio.h>

struct student {
    int no;
    char name[8];
    float score;
} s[] = {{1, "luo", 97},{2, "zhao", 95}};

int main(int argc, char *argv[])
{
    FILE *fp;
    if ((fp = fopen(argv[1], "w")) == NULL) {
        perror("fopen err");
        return -1;
    }

    fwrite(s, sizeof(struct student), 2, fp);
    return 0;
}