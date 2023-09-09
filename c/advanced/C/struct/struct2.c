#include <stdio.h>

#define N 20

struct student{
    int no;
    char name[N];
    float score;
};

void printf_into(struct student *p,int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        //	printf("%d-%s-%f\n",p->no,p->name,(*p).score);
        //	p++;
        //	printf("%d-%s-%f\n",p[i].no,p[i].name,p[i].score);
        printf("%d-%s-%f\n",(p+i)->no,(p+i)->name,(p+i)->score);
    }
}


int main(int argc, const char *argv[])
{
    struct student s1[] = {{1,"s1",90},{2,"s2",91},{3,"s3",99}};

    printf_into(s1,sizeof(s1)/sizeof(s1[0]));


    return 0;
}
