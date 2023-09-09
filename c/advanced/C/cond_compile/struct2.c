#include <stdio.h>
#include <string.h>
#define N 32
struct student{
    int no;
    char name[N];
    struct birthday{
        int year;
        int month;
        int day;
    }date;
    float score;
}s1 = {1,"s1",{1992,9,9},89};

int main(int argc, const char *argv[])
{
    struct student s2;
    s2.no = 2;
    strcpy(s2.name,"s2");
    s2.date.year = 1993;
    s2.date.month = 10;
    s2.date.day = 10;
    s2.score = 99;

    printf("%d %s %d-%d-%d %.2f\n",s1.no,s1.name,s1.date.year,s1.date.month,s1.date.day,s1.score);

    printf("%d %s %d-%d-%d %.2f\n",s2.no,s2.name,s2.date.year,s2.date.month,s2.date.day,s2.score);

    return 0;
}
