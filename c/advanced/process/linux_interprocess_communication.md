# 进程间通信(Linux Interprocess Communication)

## 早期的UNIX进程间通信方式 

### 1. 无名管道(Pipe)
无名管道特点：
- 只能用于具有亲缘关系的进程间通信，一般是父子进程或者兄弟进程间通信
- 单工通信，只能用于单向通信，具有固定的读端和写端，如果需要双向通信，需要建立两个管道
- 无名管道创建时会返回两个文件描述符，一个用于读，一个用于写，如果不需要读或者写，需要将其关闭，否则会造成资源浪费
- 只能在具有公共祖先的进程间使用，因为管道的实质是一块内核缓冲区，而该缓冲区的描述符是存放在父进程的内核栈中的，所以只能在具有公共祖先的进程间使用

无名管道的创建：
```c
#include <unistd.h>

int pipe(int fd[2]);
```
- 成功返回0，失败返回EOF
- fd[0]用于读，fd[1]用于写
- 无名管道的读写端都是阻塞的，如果读端没有数据，读端会阻塞，如果写端缓冲区满了，写端会阻塞
- 无名管道如果写端关闭，读端会读到EOF，如果读端关闭，写端会收到SIGPIPE信号，建议写端关闭

### 2. 有名管道(FIFO)
有名管道特点：
- 有名管道可以用于任意进程间通信，只要知道管道的名字(对应管道文件)
- 打开管道时可指定读写模式
- 通过文件IO操作，内容存在在内存中
- 不管是无名管道还是有名管道，只要读写两端都关闭了，那么资源就会被回收
- 有名管道的读写端都是阻塞的，如果读端没有数据，读端会阻塞，如果写端缓冲区满了，写端会阻塞

有名管道的创建：
```c
#include <unistd.h>
#include <fcntl.h>

int mkfifo(const char *pathname, mode_t mode);
```
- 成功返回0，失败返回EOF
- pathname参数指定管道的名字，对应管道文件
- mode参数指定管道的读写模式，如：0666，只有读写模式都打开，才能进行读写操作

### 3. 信号(Signal)
信号特点：
- 信号是在软件层次上对中断机制的一种模拟，信号是一种异步通信方式，信号的到来是不可预知的
- linux内核通过信号通知用户进程，不同的信号对应不同的事件，如：SIGINT对应中断信号，SIGSEGV对应段错误信号
- linux对早期UNIX的信号机制进行了扩展，早期UNIX只有32种信号(不可靠信号，会丢失)，而linux有64种信号
- 进程对信号的处理/响应方式有三种：忽略、捕捉、执行默认动作

linux下常用的信号：

| 信号名称 |                          含义                          | 默认动作 |
| :---: |:----------------------------------------------------:| :---: |
| SIGHUP |          挂起信号，该信号在用户退出shell时产生，内核发送此信号到所有子进程         | 终止进程  |
| SIGINT |   中断信号，该信号在用户键入INTR字符(ctr+c)时产生，内核发送此信号到当前终端的所有前台进程  |                 终止进程                 |
| SIGQUIT |   退出信号，该信号在用户键入QUIT字符(ctr+\)时产生，内核发送此信号到当前终端的所有前台进程  |                        终止进程                        |
| SIGILL |                非法指令信号，该信号在进程执行非法指令时产生                |                        终止进程                        |
| SIGTRAP |                跟踪陷阱信号，该信号在进程执行断点指令时产生                |                        终止进程                        |
| SIGABRT |       中止信号，该信号由abort函数调用产生，内核发送此信号到调用abort函数的进程      |                        终止进程                        |
| SIGBUS |               总线错误信号，该信号在进程访问非法内存地址时产生               |                        终止进程                        |
| SIGFPE |               浮点异常信号，该信号在进程执行非法浮点运算时产生               |                        终止进程                        |
| SIGKILL |                   杀死信号，该信号用于强制终止进程                   |                        终止进程                        |
| SIGUSR1 |                       用户自定义信号1                       |                        终止进程                        |
| SIGSEGV |                段错误信号，该信号在进程访问非法内存地址时产生               |                        终止进程                        |
| SIGUSR2 |                       用户自定义信号2                       |                        终止进程                        |
| SIGPIPE |             管道破裂信号，该信号在进程向管道写入数据，但没有读端时产生            |                        终止进程                        |
| SIGALRM |       闹钟信号，该信号由alarm函数调用产生，内核发送此信号到调用alarm函数的进程      |                        终止进程                        |
| SIGTERM |                    终止信号，该信号用于终止进程                    |                        终止进程                        |
| SIGCHLD |           子进程结束信号，该信号在子进程结束时产生，内核发送此信号到父进程           |                         忽略                         |
| SIGCONT |                   继续信号，该信号用于继续停止的进程                  |                         忽略                         |
| SIGSTOP |                    停止信号，该信号用于停止进程                    |                        停止进程                        |
| SIGTSTP |  终端停止信号，该信号在用户键入SUSP字符(ctr+z)时产生，内核发送此信号到当前终端的所有前台进程 |                        停止进程                        |
| SIGTTIN |      后台进程读终端信号，该信号在后台进程企图从终端读数据时产生，内核发送此信号到后台进程      |                         停止进程                         |
| SIGTTOU |      后台进程写终端信号，该信号在后台进程企图从终端写数据时产生，内核发送此信号到后台进程      |                         停止进程                         |
| SIGSEV |          常规错误信号，该信号在进程执行非法访问内存时产生，野指针、缓冲区溢出          |                         终止进程                         |
| SIGPWR |                电源故障信号，该信号在系统电源出现故障时产生                |                         终止进程                         |
| SIGWINCH |                窗口大小改变信号，该信号在窗口大小改变时产生                |                          忽略                          |
| SIGURG |               紧急信号，该信号在socket接收到紧急数据时产生              |                          忽略                          |
| SIGIO |                IO信号，该信号在socket接收到数据时产生               |                          忽略                          |

信号相关命令 kill/killall
```shell
# kill命令用于向指定进程发送信号，默认发送SIGTERM信号，-sig 参数指定发送的信号
kill [-signal] pid
kill -l # 列出所有信号

kill -9 1234 # 向进程号为1234的进程发送SIGKILL信号
kill -SIGKILL 1234 # 向进程号为1234的进程发送SIGKILL信号
kill -s SIGKILL 1234 # 向进程号为1234的进程发送SIGKILL信号

# 向进程组发送信号  
kill -9 -1234 # 向进程组号为1234的进程组发送SIGKILL信号

# 向所有进程发送信号
kill -9 -1 # 向当前用户的所有进程发送SIGKILL信号

# killall命令用于向指定进程名发送信号，user 参数指定用户，prog 参数指定进程名，默认发送SIGTERM信号
killall [-u user | prog] [-signal]
killall a.out
killall -u username
```

信号发送 kill/raise
```c
#include <signal.h>
#include <unistd.h>

int kill(pid_t pid, int sig);
int raise(int sig);
```
- 成功返回0，失败返回-1
- kill函数用于向指定进程发送信号，pid参数指定进程号(0代表同组进程，-1代表所有进程)，sig参数指定信号
- raise函数用于向当前进程发送信号，sig参数指定信号

信号相关函数 alarm/pause
```c
#include <unistd.h>

unsigned int alarm(unsigned int seconds);
int pause(void);
```
- 成功返回上一个定时器的剩余时间，失败返回-1
- alarm函数用于设置闹钟，seconds参数指定闹钟时间，如果seconds参数为0，表示取消闹钟
- alarm函数只能设置一个闹钟，如果设置多个闹钟，只有最后一个闹钟生效，时间到达后，内核会向进程发送SIGALRM信号
- pause函数用于挂起进程，直到收到信号，如果收到信号，pause函数返回-1，errno设置为EINTR

信号函数alarm/pause示例
```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig)
{
    printf("receive signal: %d\n", sig);
}

int main(int argc, char *argv[])
{
    // 缺省情况下，alarm函数会打印Alarm clock, 然后退出进程, 但是如果设置了定时器处理函数，就不会打印Alarm clock
    // 自定义定时器处理函数
    //signal(SIGALRM, sig_handler);
    
    alarm(5);
    pause();
    printf("pause return\n");
    return 0;
}
```

设置信号处理/响应函数 signal
```c
#include <unistd.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void (*signal(int signum, void (*handler)(int)))(int);
```
- 成功返回上一个信号处理函数，失败返回SIG_ERR
- signum参数指定信号，handler参数指定信号处理函数，如果handler参数为SIG_IGN，表示忽略信号，如果handler参数为SIG_DFL，表示执行默认动作

信号处理/响应函数 signal 示例
```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig)
{
   if (sig == SIGINT) {
       printf("receive SIGINT signal: %d\n", sig);
       exit(0);
   } else if (sig == SIGQUIT) {
       printf("receive SIGQUIT signal: %d\n", sig);
       exit(0);
   } else if (sig == SIGTSTP) {
       printf("receive SIGTSTP signal: %d\n", sig);
       exit(0);
   } 
    
}

int main(int argc, char *argv[])
{
    // 设置信号处理函数
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    signal(SIGTSTP, sig_handler);
    while (1) {
        /*printf("hello world\n");
        sleep(1);*/
        printf("pause\n");
        pause();
    }
    return 0;
}
```

## 4. System V IPC
- IPC对象包含：共享内存、信号灯集、消息队列
- IPC对象的创建和使用都需要通过IPC键值(唯一的ID)来标识，IPC键值是一个整数，可以通过ftok函数生成
- IPC对象创建后一直存在，直到系统重启或者显示删除，IPC对象的删除需要使用IPC_RMID命令，IPC对象的删除不会影响正在使用该IPC对象的进程，只有当所有进程都不再使用该IPC对象时，IPC对象才会被删除
- 每个IPC对象有一个关联的KEY
- ipcs命令用于查看IPC对象，ipcrm命令用于删除IPC对象

System V IPC对象的创建：
```c
#include <sys/types.h>
#include <sys/ipc.h>

key_t ftok(const char *pathname, int proj_id);
```
- 成功返回IPC键值(KEY)，失败返回EOF
- pathname参数指定文件名，proj_id参数指定项目ID用于生成KEY且不能为0，如果pathname参数指定的文件不存在，会创建一个文件，然后返回IPC键值，如果pathname参数指定的文件存在，会返回IPC键值，如果pathname参数指定的文件不可访问，会返回EOF

System V IPC ftok 示例：
```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>

// ./a.out .
int main(int argc, char *argv[])
{
    key_t key;
    if (argc != 2) {
        printf("usage: %s <pathname>\n", argv[0]);
        exit(1);
    }
    if ((key = ftok(argv[1], 'a')) < 0) {
        perror("ftok error");
        exit(1);
    }
    printf("key: %d\n", key);
    return 0;
}
```

## 5. 共享内存(Shared Memory)
- 共享内存是最快/最高效的IPC方式，因为共享内存是直接映射到进程的虚拟地址空间，不需要数据的拷贝
- 共享内存是一块在内核空间创建的内核缓冲区，多个进程可以将其映射到自己的虚拟地址空间，从而实现共享
- 由于多个进程可同时访问共享内存，所以需要同步和互斥机制配合使用，如：信号量

共享内存的使用步骤
- 创建/打开共享内存
- 映射共享内存，即把指定的共享内存映射到进程的虚拟地址空间用于访问
- 读写共享内存
- 解除映射共享内存
- 删除共享内存

共享内存创建 - shmget
```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int shmget(key_t key, size_t size, int shmflg);
```
- 成功返回共享内存ID，失败返回EOF
- key参数指定共享内存的KEY(IPC_PRIVATE或ftok生成)，size参数指定共享内存的大小，shmflg参数指定共享内存标志位，如：IPC_CREAT|0666

共享内存创建 - shmget 示例1
```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>

// 创建一个私有的共享内存，大小为512字节，权限为0666
// ./a.out
int main(int argc, char *argv[])
{
    int shmid;
    // 指定为私有的共享内存，大小为512字节，权限为0666(私有的共享内存只需指定0666即可)
    if ((shmid = shmget(IPC_PRIVATE, 512, 0666)) < 0) {
        perror("shmget error");
        exit(1);
    }
    printf("shmid: %d\n", shmid);
    return 0;
}
```

共享内存创建 - shmget 示例2
```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>

// 创建/打开一个和key关联的共享内存，大小为1024字节，权限为0666
// ./a.out .
int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    if (argc != 2) {
        printf("usage: %s <pathname>\n", argv[0]);
        exit(1);
    }
    
    // 指定相同的参数才能得到相同的key
    if ((key = ftok(argv[1], 'a')) < 0) {
        perror("ftok error");
        exit(1);
    }
    // 指定为共享的共享内存，大小为1024字节，权限为0666
    if ((shmid = shmget(key, 1024, IPC_CREAT|0666)) < 0) {
        perror("shmget error");
        exit(1);
    }
    printf("shmid: %d\n", shmid);
    return 0;
}
```

## 6. 消息队列(Message Queue)

## 7. 信号量集(Semaphore set)

## POSIX IPC

## 7. 套接字(Socket)













