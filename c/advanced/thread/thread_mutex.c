#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

/*
 * 线程通信 - 互斥
 *
 * 互斥锁初始化 - pthread_mutex_init() #include <pthread.h>
 * - int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
 *  - mutex：互斥锁变量
 *  - attr：互斥锁属性，通常置NULL
 *  - 返回值：成功返回0，失败返回错误编号
 *  - 注意：互斥锁的属性通常置NULL
 *
 * 释放互斥锁 - pthread_mutex_unlock() #include <pthread.h>
 * - int pthread_mutex_unlock(pthread_mutex_t *mutex);
 *   - mutex：互斥锁变量
 *   - 返回值：成功返回0，失败返回错误编号
 *   - 注意：如果互斥锁已经被释放，那么再次释放会导致错误
 *   - 注意：如果互斥锁不是当前线程锁定的，那么释放会导致错误
 *   - 注意：如果互斥锁的值不为0，那么释放会导致错误
 *
 * # 不使用条件编译
 * gcc -o thread_mutex thread_mutex.c -lpthread
 * ./thread_mutex
 *
 * # 使用条件编译
 * gcc -o thread_mutex thread_mutex.c -lpthread -D_LOCK_
 * ./thread_mutex
 *
 */

unsigned int count, value1, value2;
pthread_mutex_t lock;

void *function(void *arg);

int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret;

    ret = pthread_mutex_init(&lock, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_mutex_init: %s\n", strerror(ret));
        exit(1);
    }

    ret = pthread_create(&tid, NULL, function, NULL);
    if (ret != 0) {
        fprintf(stderr, "pthread_create: %s\n", strerror(ret));
        exit(1);
    }

    while (1) {
        count++;
#ifdef _LOCK_
        pthread_mutex_lock(&lock);
#endif
        value1 = count;
        value2 = count;
#ifdef _LOCK_
        pthread_mutex_unlock(&lock);
#endif
    }

    return 0;
}

void *function(void *arg) {
    while (1) {
#ifdef _LOCK_
        pthread_mutex_lock(&lock);
#endif
        if (value1 != value2) {
            printf("value1 = %u, value2 = %u\n", value1, value2);
            usleep(100000);
        }
#ifdef _LOCK_
        pthread_mutex_unlock(&lock);
#endif
    }
    return NULL;
}
