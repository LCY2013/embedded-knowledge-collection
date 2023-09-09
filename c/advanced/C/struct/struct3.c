#include <stdio.h>

#define N 20

struct student{
    int no;
    char name[N];
    float score;
}s2[5];

int main(int argc, const char *argv[])
{
    int i;
    struct student s1[5] = {{1,"s1",90},{2,"s2",91},{3,"s3",99}};

    printf("%d-%s-%f\n",s1[0].no,s1[0].name,s1[0].score);

    s2[0] = s1[0];
    s2[1] = s1[1];
    s2[2] = s1[2];

    for(i = 0;i < sizeof(s2)/sizeof(struct student);i++)
    {
        printf("%d-%s-%f\n",s2[i].no,s2[i].name,s2[i].score);
    }
    return 0;
}
