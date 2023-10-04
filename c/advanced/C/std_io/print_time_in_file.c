#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
 *  ./a.out time.txt
 */

int main(int argc, char *argv[])
{
    FILE *fp;
    int line = 0;
    char buf[64];
    time_t t;
    struct tm *tp;

    if ((fp = fopen(argv[1], "a+")) == NULL) {
        ferror(fp);
        return -1;
    }

    while (fgets(buf, 64, fp) != NULL) {
        if (buf[strlen(buf)-1] == '\n') {
            line++;
        }
    }

    while ( 1 ) {
        time(&t);
        tp = localtime(&t);
        fprintf(fp, "%02d %d-%02d-%02d %02d:%2d:%2d\n", ++line, tp->tm_year + 1900, tp->tm_mon + 1,
                tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
        fflush(fp);
        sleep(1);
    }

    return 0;
}