#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

char message[32] = "Hello World";

void *thread_func(void *arg) {
    sleep(1);
    strcpy(message, "Hello, marked by Thread");
    pthread_exit("thank you for the waiting for me");
}

/*
 * gcc -o thread_demo thread_demo.c -lpthread
 */
int main(int argc, char *argv[])
{
    pthread_t tid;
    int ret;
    void *retValue;
    ret = pthread_create(&tid, NULL, thread_func, (void *)message);
    if (ret != 0) {
        perror("pthread_create error");
        exit(1);
    }
    printf("main: pid = %d, tid = %lu\n", getpid(), pthread_self());
    printf("main: thread created, tid = %lu\n", tid);
    ret = pthread_join(tid, &retValue);
    if (ret != 0) {
        perror("pthread_join error");
        exit(1);
    }
    printf("main: thread exited, retValue = %s\n", (char *)retValue);
    printf("main: message = %s\n", message);
    return 0;
}