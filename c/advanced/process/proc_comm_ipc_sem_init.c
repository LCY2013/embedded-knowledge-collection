#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

// 信号灯集初始化 - 示例
// 假设信号灯集合中包含两个信号灯，第一个初始化为2，第二个初始化为0
// ./a.out

int main(int argc, char *argv[]) {
    int semid;
    key_t key;
    union semun myun;

    if ((key = ftok(".", 's')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // 创建信号灯集，权限为IPC_CREAT|0666
    if ((semid = semget(key, 2, IPC_CREAT|0666)) < 0) {
        perror("semget error");
        exit(1);
    }

    myun.val = 2;
    if (semctl(semid, 0, SETVAL, myun) < 0) {
        perror("semctl error");
        exit(-1);
    }

    myun.val = 0;
    if (semctl(semid, 1, SETVAL, myun) < 0) {
        perror("semctl error");
        exit(-1);
    }

    return 0;
}