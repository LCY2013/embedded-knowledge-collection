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

// 从消息队列中接收消息
// ./a.out
int main(int argc, char *argv[])
{
    int msgid;
    key_t key;
    MSG msg;

    if((key = ftok(".", 'q')) == -1) {
        perror("ftok error");
        exit(1);
    }

    // 指定消息队列，权限为IPC_CREAT|0666
    if ((msgid = msgget(key, IPC_CREAT|0666)) < 0) {
        perror("msgget error");
        exit(1);
    }
    printf("msgid: %d\n", msgid);

    // 接收消息
    while (1) {
        //if (msgrcv(msgid, &msg, 512, 0, 0) < 0) {
        if (msgrcv(msgid, &msg, LEN, 1, 0) < 0) {
            perror("msgrcv error");
            exit(1);
        }
        printf("msg.mtype: %ld\n", msg.mtype);
        printf("msg.mtext: %s\n", msg.mtext);
    }
    return 0;
}