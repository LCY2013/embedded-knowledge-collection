#ifndef __NET_H__
#define __NET_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <pthread.h>

#define SERV_PORT 5001
#define SERV_IP_ADDR "192.168.3.110"
#define BACKLOG 5

#define QUIT_STR "quit"

struct cli_info {
    //struct list_head list; /* 内核链表*/
    int cli_fd;
    struct sockaddr_in cin;
    int qq_num;
    char nick[32];
    //...
};

#endif