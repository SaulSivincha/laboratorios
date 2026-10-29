#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int shared = 1;
pthread_mutex_t l;

void *fun1(void *arg)
{
    (void)arg;
    int x;
    printf("Thread 1 trying to acquire the lock\n");
    pthread_mutex_lock(&l);
    printf("Thread 1 acquired the lock\n");
    x = shared;
    printf("Thread 1 reads the shared value: %d\n", x);
    x++;
    printf("Thread 1 local update: %d\n", x);
    sleep(1);
    shared = x;
    printf("Thread 1 updated shared value to: %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("Thread 1 released the lock\n");
    return NULL;
}

void *fun2(void *arg)
{
    (void)arg;
    int y;
    printf("Thread 2 trying to acquire the lock\n");
    pthread_mutex_lock(&l);
    printf("Thread 2 acquired the lock\n");
    y = shared;
    printf("Thread 2 reads the shared value: %d\n", y);
    y--;
    printf("Thread 2 local update: %d\n", y);
    sleep(1);
    shared = y;
    printf("Thread 2 updated shared value to: %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("Thread 2 released the lock\n");
    return NULL;
}

int main(void)
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&l, NULL);
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final shared variable value is %d\n", shared);
    pthread_mutex_destroy(&l);
    return 0;
}
