#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>

// 创建一个私有的共享内存，大小为512字节，权限为0666
// ./a.out
int main(int argc, char *argv[])
{
    int shmid;
    // 指定为私有的共享内存，大小为512字节，权限为0666(私有的共享内存只需指定0666即可)
    if ((shmid = shmget(IPC_PRIVATE, 512, 0666)) < 0) {
        perror("shmget error");
        exit(1);
    }
    printf("shmid: %d\n", shmid);
    return 0;
}