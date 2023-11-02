#include "net.h"

int main(void) {
    int fd = -1;
    struct sockaddr_in sin;
    char buf[BUFSIZ];

    /* 1.创建socket fd*/
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(-1);
    }

    /*2.连接服务器*/
    /*2.1 填充struct socket_in结构体变量*/
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERV_PORT); //网络字节序的端口号
    sin.sin_addr.s_addr = inet_addr(SERV_IP_ADDR);

    /*2.2 链接服务器*/
    if (connect(fd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("connect");
        exit(-1);
    }
    printf("Client staring...OK!\n");
    /*3. 读写数据*/
    int ret = -1;
    while (1) {
        bzero(buf, BUFSIZ);
        if (fgets(buf, BUFSIZ - 1, stdin) == NULL) {
            continue;
        }
        do {
            /*把buf中的数据写到网络套接字中*/
            ret = write(fd, buf, strlen(buf));
        } while (ret < 0 && EINTR == errno);

        if (!strncasecmp(buf, QUIT_STR, strlen(QUIT_STR))) { // 用户输入quit字符
            break;
        }
    }

    /*4. 关闭套接字*/
    close(fd);
    return 0;
}