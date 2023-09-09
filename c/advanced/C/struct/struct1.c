#include <stdio.h>

#define N 20

struct student{
    int no;
    char name[N];
    float score;
};

int main(int argc, const char *argv[])
{
    int i;
    struct student s1[] = {{1,"s1",90},{2,"s2",91},{3,"s3",99}};
    struct student *p;
    p = s1;
    p = &s1[0];

    for(i = 0;i < sizeof(s1)/sizeof(struct student);i++)
    {
        printf("--%d-%s-%f--\n",p->no,p->name,(*p).score);
        p++;
    }


    return 0;
}
