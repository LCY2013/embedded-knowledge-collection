#include <stdio.h>

/*
➜  io git:(main) ✗ ./cp cp.c cp.c.bak
➜  io git:(main) ✗ diff -ruN cp.c cp.c.bak
 */

#define N 64

int main(int argc, char *argv[])
{
    FILE *fps, *fpd;
    char buf[N];
    int n;

    if (argc < 3) {
        printf("Usage : %s <src_file> <dst_file>\n", argv[0]);
        return -1;
    }

    if ((fps = fopen(argv[1], "r")) == NULL) {
        perror("fopen src file err");
        return -1;
    }

    if ((fpd = fopen(argv[2], "w")) == NULL) {
        perror("fopen dst file err");
        return -1;
    }
    while ((n = fread(buf, 1, N,fps)) > 0) {
        fwrite(buf, 1, n, fpd);
    }

    fclose(fps);
    fclose(fpd);
    return 0;
}
