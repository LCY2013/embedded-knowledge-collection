#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "const_head.h"

int main(int argc, char *argv[])
{
    int msgid;
    key_t key;
    MSG msg;

    if((key = ftok(".", 'q')) == -1) {
        perror("ftok error");
        exit(1);
    }

    printf("client 2 key: %d\n", key);

    // 指定消息队列，权限为IPC_CREAT|0666
    // 不存在创建，存在返回
    if ((msgid = msgget(key, IPC_CREAT|0666)) < 0) {
        perror("msgget error");
        exit(1);
    }
    printf("client 2 msgid: %d\n", msgid);

    // 接收消息
    while (1) {
        // 接收消息
        if (msgrcv(msgid, &msg, LEN, C2_TYPE, 0) < 0) {
            perror("msgrcv error");
            exit(1);
        }
        if (strncmp(msg.mtext, "exit", 4) == 0 ||
            strncmp(msg.mtext, "quit", 4) == 0) {
            break;
        }
        printf("recv mtype: %ld, mtext: %s\n", msg.mtype, msg.mtext);

        // 构建消息体
        msg.mtype = C1_TYPE;
        printf("intput > ");
        fgets(msg.mtext, LEN, stdin);
        if (strncmp(msg.mtext, "exit", 4) == 0 ||
            strncmp(msg.mtext, "quit", 4) == 0) {
            break;
        }
        // 发送消息
        msgsnd(msgid, &msg, LEN, 0);
    }

    // 删除消息队列
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}


