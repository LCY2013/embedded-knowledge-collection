// Command: gcc -o const_head const_head.c
// 有名管道名称
char *FIFO_NAME = "myfifo";
int N = 64;

// 消息队列名称
char MSG_NAME = 'q';

// mq消息结构
typedef struct {
    long mtype;
    char mtext[64];
} MSG;

#define LEN (sizeof(MSG) - sizeof(long))

#define C1_TYPE 100
#define C2_TYPE 200

// 信号灯集与共享内存示例定义
int READ = 0;
int WRITE = 1;

//union semun {
//    int val;
//    struct semid_ds *buf;
//    unsigned short *array;
//    struct seminfo *__buf;
//};
