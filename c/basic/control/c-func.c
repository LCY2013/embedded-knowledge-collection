#include "c-head.h"

void PrimeNumber() {
    int i, j;

    while (1) {
        printf(">");
        if (scanf("%d", &i) == 0) {
            while (getchar() != 10) {

                continue;
            }
        }
        if (i == -1)
            break;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i)) {
            printf("%d\n", i);
        } else {
            printf("not prime number\n");
        }
    }
}

void If() {
    int x = 7;
    if (x + 1 == 8)
        printf("if:x=%d\n", x);
    else
        printf("else:x=%d\n", x);
}

void leapOne() {
    int year = 2000, n = 0;

    while (year <= 2500) {
        if (year % 4 == 0) {
            if (year % 100 != 0) {
                printf("%d is leap\n", year);
                n++;
            }
            else {
                if (year % 400 == 0) {
                    printf("%d is leap\n", year);
                    n++;
                }
            }
        }
        year++;
    }
    printf("n=%d\n", n);
}

void leapTwo() {
    int year = 2000, n = 0;

    while (year <= 2500) {
        if (year % 4 == 0 && year % 100 != 0) {
            printf("%d is leap\n", year);
            n++;
        }
        if (year % 100 == 0 && year % 400 == 0) {
            printf("%d is leap\n", year);
            n++;
        }
        year++;
    }
    printf("n=%d\n", n);
}

void leapThree() {
    int year = 2000, n = 0;

    while (year <= 2500) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            printf("%d is leap\n", year);
            n++;
        }

        year++;
    }
    printf("n=%d\n", n);
}

void Score1() {
    float score;

    printf("please input your score:");
    scanf("%f", &score);

    if (score < 0 || score > 100) {
        printf("not in [0, 100]\n");
        return;
    }

    if (score >= 90)
        printf("A-good\n");
}

void Score2() {
    float score;

    printf("please input your score:");
    scanf("%f", &score);

    if (score < 0 || score > 100) {
        printf("not in [0, 100]\n");
    }
    else {
        if (score >= 90)
            printf("A-excellent\n");
        else {//[...,90)
            if (score >= 70) //[70,90)
                printf("B-good\n");
            else {//[...,70)
                if (score >= 60)//[60,70)
                    printf("C-OK\n");
                else
                    printf("D-not pass\n");
            }
        }
    }
}

void Score3() {
    float score;

    printf("please input your score:");
    scanf("%f", &score);

    if (!(score >= 0 && score <= 100)) {
        printf("not in [0, 100]\n");
    }
    else {
        if (score >= 90)
            printf("A-excellent\n");
        else {//[...,90)
            if (score >= 70) //[70,90)
                printf("B-good\n");
            else {//[...,70)
                if (score >= 60)//[60,70)
                    printf("C-OK\n");
                else
                    printf("D-not pass\n");
            }
        }
    }
}

void Score4() {
    float score;

    printf("please input your score:");
    scanf("%f", &score);

    if (!(score >= 0 && score <= 100))
        printf("not in [0, 100]\n");
    else if (score >= 90)
        printf("A-excellent\n");
    else if (score >= 70)
        printf("B-good\n");
    else if (score >= 60)
        printf("C-OK\n");
    else
        printf("D-not pass\n");
}

void Triangle() {
    float a, b, c;
    float p;
    float area;

    printf("input a b c:");
    scanf("%f%f%f", &a, &b, &c);

    if ( a + b <= c || a + c <= b || b + c <= a) {
        printf("invalid input--1\n");
        return;
    }
    if (abs(a - b) >= c || abs(a - c) >= b || abs(b - c) >= a) {
        printf("invalid input--2\n");
        return;
    }

    p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("%.2f, %.2f, %.2f--->%.2f\n", a, b, c, area);

}

void TriangleOne() {
    float a, b, c;
    float p;
    float area;

    printf("input a b c:");
    scanf("%f%f%f", &a, &b, &c);

    if ( a + b <= c || a + c <= b || b + c <= a || abs(a - b) >= c || abs(a - c) >= b || abs(b - c) >= a) {
        printf("invalid input\n");
    } else {
        p = (a + b + c) / 2;
        area = sqrt(p * (p - a) * (p - b) * (p - c));

        printf("%.2f, %.2f, %.2f--->%.2f\n", a, b, c, area);
    }
}

void Ls(int argc, char *argv[]) {
    struct stat buf;
    struct tm *t;
    int i = 8;
    if (argc < 2)
    {
        fprintf(stdout, "usage:%s filename\n", argv[0]);
        return;
    }

    if (lstat(argv[1], &buf) == -1)
    {
        perror("stat");
        return;
    }

    switch (buf.st_mode & S_IFMT)
    {
        case S_IFBLK:	printf("b");	break;
        case S_IFCHR:	printf("c");	break;
        case S_IFDIR:	printf("d");	break;
        case S_IFREG:	printf("-");	break;
        case S_IFLNK:	printf("l");	break;
        case S_IFSOCK:	printf("s");	break;
        case S_IFIFO:	printf("p");	break;
        default:		printf("?");
    }

    while (i >= 0)
    {
        if (buf.st_mode & 1 << i)
        {
            switch (i % 3)
            {
                case 2:	printf("r");	break;
                case 1:	printf("w");	break;
                case 0:	printf("x");	break;
            }

        }
        else
            printf("-");
        i--;
    }

    fprintf(stdout, " %d %d %d %ld", buf.st_nlink, buf.st_uid, buf.st_gid,
            buf.st_size);

    t = localtime(&buf.st_mtime);
    fprintf(stdout, " %d-%d-%d %d:%d %s\n",t->tm_year+1900, t->tm_mon+1,
            t->tm_mday,t->tm_hour, t->tm_min,argv[1]);
}


