#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "const_head.h"

// 信号灯集初始化 - 示例
// 父子进程通过System V信号灯同步对共享内存的读写
// 1、父进程从键盘输入字符串到共享内存
// 2、子进程从共享内存中读取字符串后删除字符串中的空格并打印到屏幕
// 3、父子进程交替执行，直到父进程输入quit时，删除共享内存和信号灯集后退出

void init_sem(int semid, int s[], int n)
{
    int i;
    union semun myun;

    for (i = 0; i < n; i++) {
        myun.val = s[i];
        if (semctl(semid, i, SETVAL, myun) < 0) {
            perror("semctl error");
            exit(-1);
        }
    }
}

void pv(int semid, int num, int op)
{
    struct sembuf mybuf;

    mybuf.sem_num = num;
    mybuf.sem_op = op;
    mybuf.sem_flg = 0;

    if (semop(semid, &mybuf, 1) < 0) {
        perror("semop error");
        exit(-1);
    }
}

int main(int argc, char *argv[]) {
    int semid, shmid, s[]={0,1};
    key_t key;
    char *shmaddr, *q, *p;
    pid_t pid;

    if ((key = ftok(".", 's')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // 创建共享内存，权限为IPC_CREAT|0666
    if ((shmid = shmget(key, N, IPC_CREAT | 0666)) < 0) {
        perror("shmget error");
        exit(1);
    }

    // 创建信号灯集，权限为IPC_CREAT|0666
    if ((semid = semget(key, 2, IPC_CREAT | 0666)) < 0) {
        perror("semget error");
        // 移除创建的共享内存
        goto _error1;
    }

    // 初始化信号灯集
    init_sem(semid, s, 2);

    // 映射共享内存
    if ((shmaddr = shmat(shmid, NULL, 0)) == (void *) -1) {
        perror("shmat error");
        goto _error2;
    }

    // 创建一个子进程
    if ((pid = fork()) < 0) {
        perror("fork error");
        goto _error2;
    } else if (pid == 0) {
        while (1) {
            pv(semid, READ, -1);
            p = q = shmaddr;
            while (*p) {
                if (*p != ' ') {
                    *q++ = *p;
                }
                p++;
            }
            *q = '\0';
            printf("Output > %s\n", shmaddr);
            pv(semid, WRITE, 1);
        }
    } else {
        while (1) {
            pv(semid, WRITE, -1);
            printf("Input > ");
            fgets(shmaddr, N, stdin);
            if (strncmp(shmaddr, "quit", 4) == 0) {
                break;
            }
            pv(semid, READ, 1);
        }
        kill(pid, SIGUSR1);
    }

_error1:
    shmctl(shmid, IPC_RMID, NULL);

_error2:
    semctl(semid, 0, IPC_RMID, NULL);

    return 0;
}