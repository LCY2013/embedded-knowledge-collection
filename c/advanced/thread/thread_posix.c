#include <stdio.h>
#include <semaphore.h>

/*
 * Posix 信号量
 * - 无名信号量（基于内存的信号量）
 * - 有名信号量（基于文件的信号量）
 *
 * pthread库常用的信号量操作函数如下：
 * - sem_init()：初始化信号量 int sem_init(sem_t *sem, int pshared, unsigned int value);
 *   - sem：信号量变量
 *   - pshared：0表示线程间共享，非0表示进程间共享
 *   - value：信号量的初始值
 *   - 返回值：成功返回0，失败返回-1
 *   - 注意：信号量的初始值不能为负数
 *   - 注意：信号量的初始值不能大于信号量的最大值
 *   - 注意：信号量的最大值是多少？这个值是由系统决定的，可以通过命令查看：
 *   - cat /proc/sys/kernel/sem
 *   - 信号量的最大值是32767
 *   - 信号量的最大值可以通过命令修改：
 *   - echo 65535 > /proc/sys/kernel/sem
 *   - 注意：修改信号量的最大值需要root权限
 * - sem_destroy()：销毁信号量 int sem_destroy(sem_t *sem);
 *   - sem：信号量变量
 *   - 返回值：成功返回0，失败返回-1
 *   - 注意：销毁信号量之前，必须保证信号量的值为0
 *   - 注意：销毁信号量之前，必须保证没有线程或进程在使用信号量
 * - sem_wait()：等待信号量 p操作 int sem_wait(sem_t *sem);
 *   - sem：信号量变量
 *   - 返回值：成功返回0，失败返回-1
 *   - 注意：如果信号量的值大于0，那么就将信号量的值减1，然后继续执行
 *   - 注意：如果信号量的值等于0，那么就阻塞等待，直到信号量的值大于0
 *   - 注意：如果信号量的值小于0，那么就阻塞等待，直到信号量的值大于0
 * - sem_post()：释放信号量 v操作 int sem_post(sem_t *sem);
 *   - sem：信号量变量
 *   - 返回值：成功返回0，失败返回-1
 *   - 注意：将信号量的值加1
 *   - 注意：如果有线程或进程阻塞等待信号量，那么就唤醒其中一个
 *   - 注意：如果没有线程或进程阻塞等待信号量，那么就将信号量的值加1
 *   - 注意：如果信号量的值小于0，那么就唤醒其中一个
 *   - 注意：如果信号量的值等于0，那么就将信号量的值加1
 *   - 注意：如果信号量的值大于0，那么就将信号量的值加1
 *   - 注意：如果信号量的值大于信号量的最大值，那么就将信号量的值设置为信号量的最大值
 *
 * 信号量的使用步骤：
 * - 定义信号量 sem_t sem;
 * - 初始化信号量 sem_init(&sem, 0, 1);
 * - 使用信号量 sem_wait(&sem); sem_post(&sem);
 * - 销毁信号量 sem_destroy(&sem);
 *
 */

int main(int argc, char** argv) {

    return 0;
}