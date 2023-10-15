#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    long mtype;
    char mtext[512];
} MSG;

#define LEN (sizeof(MSG) - sizeof(long))

// 向消息队列中发送消息
// ./a.out
int main(int argc, char *argv[])
{
    int msgid;
    key_t key;

    if((key == ftok(".", 'q')) == -1) {
        perror("ftok error");
        exit(1);
    }

    /*struct msgbuf {
        long mtype;
        char mtext[512];
    } msg;*/
    MSG msg;

    // 指定消息队列，权限为IPC_CREAT|0666
    if ((msgid = msgget(key, IPC_CREAT|0666)) < 0) {
        perror("msgget error");
        exit(1);
    }
    printf("msgid: %d\n", msgid);

    // 发送消息
    msg.mtype = 1;
    while (1) {
        fgets(msg.mtext, 512, stdin);
        if (strncmp(msg.mtext, "quit", 4) == 0) {
            break;
        }
        //if (msgsnd(msgid, &msg, strlen(msg.mtext), 0) < 0) {
        if (msgsnd(msgid, &msg, LEN, 0) < 0) {
            perror("msgsnd error");
            exit(1);
        }
    }
    return 0;
}