# linux thread
- [thread 概念](#thread概念)
- [thread 特点](#thread特点)
- [thread 共享资源](#thread共享资源)
- [Linux 线程库](#Linux线程库)

## thread概念
- 进程在切换时系统开销较大，因此引入了线程的概念。
- 很多操作系统引入了轻量级进程LWP
- 同一进程中的线程共享进程相同地址空间(资源，如内存、文件、信号等)。
- Linux不区分线程和进程，线程也是一种进程，只是线程共享了进程的资源。

## thread特点
- 通常线程指的是共享相同地址空间的多个任务(task_struct)。
- 使用多线程的好处（大大提高了任务切换的效率，避免了额外的TLB & cache的刷新）

## thread共享资源
- 线程共享的资源包括：
  - 进程代码段，可执行的指令，静态数据，动态分配的内存
  - 进程的公有数据（利用这些共享的数据，线程很容易的实现相互之间的通信）
  - 进程打开的文件描述符、信号的处理器、进程的当前目录和进程用户ID与进程组ID
- 线程不共享的资源包括：
  - 线程ID（TID）
  - PC（程序计数器）和相关寄存器组的值
  - 线程的栈
  - 错误返回码（errno）
  - 线程的信号屏蔽码
  - 线程的优先级
  - 执行状态和属性（如SCHED_FIFO、SCHED_RR等）

## Linux线程库
- Linux线程库有两种实现方式：
  - NPTL（Native POSIX Thread Library）：LinuxThreads的改进版，是Linux系统默认的线程库。
  - LinuxThreads：Linux系统早期的线程库，已经被NPTL取代。

- pthread线程库提供了如下基本操作
  - 创建线程
  - 终止线程
  - 回收线程

- 同步和互斥机制
  - 互斥锁
  - 条件变量
  - 读写锁
  - 自旋锁
  - 信号量
  - 屏障
  - 互斥量

## Linux线程库函数
- [线程创建 - pthread_create](#线程创建---pthreadcreate)
- [线程回收 - pthread_join](#线程回收---pthreadjoin)
- [线程终止 - pthread_exit](#线程终止---pthreadexit)
 
### 线程创建 - pthread_create
```c
#include <pthread.h>
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
```
- thread：线程ID
- attr：线程属性，通常为NULL
- start_routine：线程函数
- arg：线程函数参数
- 返回值：成功返回0，失败返回错误码
- 示例
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg)
{
    printf("thread_func: pid = %d, tid = %lu\n", getpid(), pthread_self());
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    if (pthread_create(&tid, NULL, thread_func, NULL) != 0) {
        perror("pthread_create error");
        exit(1);
    }
    sleep(1);
    return 0;
}
```

### 线程回收 - pthread_join
```c
#include <pthread.h>
int pthread_join(pthread_t thread, void **retval);
```
- thread：线程ID
- retval：线程函数返回值
- 返回值：成功返回0，失败返回错误码
- 示例
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg)
{
    printf("thread_func: pid = %d, tid = %lu\n", getpid(), pthread_self());
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    if (pthread_create(&tid, NULL, thread_func, NULL) != 0) {
        perror("pthread_create error");
        exit(1);
    }
    if (pthread_join(tid, NULL) != 0) {
        perror("pthread_join error");
        exit(1);
    }
    return 0;
}
```

### 线程终止 - pthread_exit
```c
#include <pthread.h>
void pthread_exit(void *retval);
```
- retval：线程函数返回值
- 示例
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg)
{
    printf("thread_func: pid = %d, tid = %lu\n", getpid(), pthread_self());
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    if (pthread_create(&tid, NULL, thread_func, NULL) != 0) {
        perror("pthread_create error");
        exit(1);
    }
   
    if (pthread_exit(NULL) != 0) {
        perror("pthread_exit error");
        exit(1);
    }
    return 0;
}
```

### 线程使用示例  
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

char message[] = "Hello World";
void *thread_func(void *arg);

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret;
    void *retval;
    ret = pthread_create(&tid, NULL, thread_func, (void *)message);
    if (ret != 0) {
        perror("pthread_create error");
        exit(1);
    }
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    printf("main: thread created, tid = %lu\n", tid);
    ret = pthread_join(tid, &retval);
    if (ret != 0) {
        perror("pthread_join error");
        exit(1);
    }
    printf("main: thread exited, retval = %ld\n", (long)retval);
    return 0;
}

```

### 获取线程id
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_func(void *arg);

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret;
    void *retval;
    ret = pthread_create(&tid, NULL, thread_func, NULL);
    if (ret != 0) {
        perror("pthread_create error");
        exit(1);
    }
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    printf("main: thread created, tid = %lu\n", tid);
    ret = pthread_join(tid, &retval);
    if (ret != 0) {
        perror("pthread_join error");
        exit(1);
    }
    printf("main: thread exited, retval = %ld\n", (long)retval);
    return 0;
}

void *thread_func(void *arg)
{
    printf("thread_func: pid = %d, tid = %lu\n", getpid(), pthread_self());
    return (void *)pthread_self();
}
```


