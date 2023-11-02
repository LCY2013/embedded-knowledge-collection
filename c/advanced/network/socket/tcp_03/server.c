#include "net.h"

void *cli_data_handle(void *arg);

int main(void) {
    int fd = -1, newfd;
    struct sockaddr_in sin;

    /* 1. 创建IPV4的TCP socket fd*/
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error!");
        exit(-1);
    }

    /* 允许本地的地址和端口快速重用 */
    int b_reuse = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (void *) &b_reuse, sizeof(b_reuse)) < 0) {
        perror("setsockopt");
        exit(-1);
    }

    /*2. 绑定 */
    /*2.1 填充struct sockaddr_in结构体变量 */
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET; //该函数将sin结构体中的sin_family成员赋值为AF_INET，AF_INET是地址族标识，表示使用IPv4地址族。
    sin.sin_port = htons(SERV_PORT); //网络字节序的端口号

    /*优化1: 接收从本机任意IP地址过来的发给TCP，SERV_PORT的数据 */
    sin.sin_addr.s_addr = htonl(INADDR_ANY);

    /*2.2 绑定 */
    if (bind(fd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("bind");
        exit(-1);
    }
    /*3. 调用listen()把主动套接字变成被动套接字 */
    if (listen(fd, BACKLOG) < 0) {
        perror("listen");
        exit(-1);
    }

    printf("Server starting....OK!\n");

    /*4. 读写 */
    //..和newfd进行数据读写
    pthread_t tid;
    while (1) {
        struct cli_info *pcinfo = NULL;

        struct sockaddr_in cin;
        socklen_t clen = sizeof(cin);
        /*等待客户端连接*/
        do {
            newfd = accept(fd, (struct sockaddr *) &cin, &clen);
        } while (newfd < 0 && EINTR == errno);

        if (newfd < 0) {
            perror("accept");
            exit(-1);
        }

        /* 填充客户端信息 */
        pcinfo = (struct cli_info *) malloc(sizeof(struct cli_info));

        // 使用bzero函数将pcinfo结构体中的所有字节都设置为0
        // pcinfo是指向struct cli_info结构体的指针
        // sizeof(struct cli_info)表示将pcinfo结构体的所有字节都设置为0的大小
        bzero(pcinfo, sizeof(struct cli_info));

        //填充内核链表
        //....FIXME!!!!
        pcinfo->cli_fd = newfd;
        memcpy(&pcinfo->cin, &cin, sizeof(cin));
        //...填充其他数据
        //....FIXME!!!
        //把cinfo加入到user_info内核链表
        //...FIXME!!
        if (pthread_create(&tid, NULL, cli_data_handle, (void *) pcinfo) < 0) {
            perror("pthread_create");
            exit(-1);
        }
        pthread_detach(tid);
    }

    close(fd);

    return 0;
}

void *cli_data_handle(void *arg) {
    struct cli_info *pcinfo = (struct cli_info *) arg;
    char buf[BUFSIZ];
    char ipaddr[16];
    int ret = -1;

    /*设置线程的分离属性*/
    /*if (pthread_detach(pthread_self()) < 0) {
        perror("pthread_detach");
        exit(-1);
    }*/

    int newfd = pcinfo->cli_fd;
    struct sockaddr_in cin;

    memcpy(&cin, &pcinfo->cin, sizeof(cin));

    bzero(ipaddr, 16);
    if (!inet_ntop(AF_INET, (void *) &cin.sin_addr, ipaddr, sizeof(ipaddr))) {
        perror("inet_ntop");
        exit(-1);
    }
    printf("Client(%s:%d) is connected!\n", ipaddr, ntohs(cin.sin_port));

    /*5、和客户端进行信息的交互(读写)*/
    while (1) {
        bzero(buf, BUFSIZ);

        do {
            ret = read(newfd, buf, BUFSIZ - 1);
        } while (ret < 0 && EINTR == errno);
        if (ret < 0) {
            continue;
        }
        /*处理数据*/
        //...
        printf("Receive data: %s\n", buf);
        if (!ret || !strncasecmp(buf, QUIT_STR, strlen(QUIT_STR))) {
            //...FIXME!!, 删除cli_info的所占内存
            free(pcinfo);
            break;
        }
    }

    close(newfd);

    return NULL;
}