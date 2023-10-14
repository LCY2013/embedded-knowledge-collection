#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>

// 创建/打开一个和key关联的共享内存，大小为1024字节，权限为0666
// ./a.out .
int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    if (argc != 2) {
        printf("usage: %s <pathname>\n", argv[0]);
        exit(1);
    }

    // 指定相同的参数才能得到相同的key
    if ((key = ftok(argv[1], 'a')) < 0) {
        perror("ftok error");
        exit(1);
    }
    // 指定为共享的共享内存，大小为1024字节，权限为0666
    if ((shmid = shmget(key, 1024, IPC_CREAT|0666)) < 0) {
        perror("shmget error");
        exit(1);
    }
    printf("shmid: %d\n", shmid);
    return 0;
}