#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void *print_i(void *ptr)
{
    (void)ptr;
    pthread_mutex_lock(&mutex1);
    printf("Thread i holds mutex1 and requests mutex2\n");
    sleep(1);
    pthread_mutex_lock(&mutex2);
    printf("I am in i\n");
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

void *print_j(void *ptr)
{
    (void)ptr;
    pthread_mutex_lock(&mutex2);
    printf("Thread j holds mutex2 and requests mutex1\n");
    sleep(1);
    pthread_mutex_lock(&mutex1);
    printf("I am in j\n");
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

int main(void)
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, print_i, NULL);
    pthread_create(&t2, NULL, print_j, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
