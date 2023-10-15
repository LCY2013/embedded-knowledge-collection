#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// 在共享内存中存放键盘输入的字符串
// ./a.out
int main(int argc, char *argv[])
{
    int shmid;
    char *ptr;
    // 指定为私有的共享内存，大小为512字节，权限为0666(私有的共享内存只需指定0666即可)
    if ((shmid = shmget(IPC_PRIVATE, 512, 0666)) < 0) {
        perror("shmget error");
        exit(1);
    }
    printf("shmid: %d\n", shmid);

    // 映射共享内存
    if ((ptr = shmat(shmid, NULL, 0)) == (void *)-1) {
        perror("shmat error");
        exit(1);
    }

    // 读写共享内存
    while (1) {
        fgets(ptr, 512, stdin);
        if (strncmp(ptr, "quit", 4) == 0) {
            break;
        }
    }

    // 解除映射共享内存
    if (shmdt(ptr) < 0) {
        perror("shmdt error");
        exit(1);
    }

    // 删除共享内存
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmctl error");
        exit(1);
    }
    return 0;
}