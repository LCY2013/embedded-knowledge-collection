#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>

// ./a.out .
int main(int argc, char *argv[])
{
    key_t key;
    if (argc != 2) {
        printf("usage: %s <pathname>\n", argv[0]);
        exit(1);
    }
    if ((key = ftok(argv[1], 'a')) < 0) {
        perror("ftok error");
        exit(1);
    }
    printf("key: %d\n", key);
    return 0;
}