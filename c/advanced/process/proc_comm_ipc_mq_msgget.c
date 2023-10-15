#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include "const_head.h"

// 创建一个消息队列，权限为0666
// ./a.out
int main(int argc, char *argv[])
{
    int msgid;
    key_t key;

    if((key == ftok(".", MSG_NAME)) == -1) {
        perror("ftok error");
        exit(1);
    }

    // 指定消息队列，权限为IPC_CREAT|0666
    if ((msgid = msgget(key, IPC_CREAT|0666)) < 0) {
        perror("msgget error");
        exit(1);
    }
    printf("msgid: %d\n", msgid);
    return 0;
}