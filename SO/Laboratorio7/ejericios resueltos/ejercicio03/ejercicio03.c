#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void print(char *a, char *b)
{
    pthread_mutex_lock(&mutex1);
    printf("1: %s\n", a);
    sleep(1);
    printf("2: %s\n", b);
    pthread_mutex_unlock(&mutex1);
}

void *print_i(void *ptr)
{
    (void)ptr;
    print("I am", " in i");
    return NULL;
}

void *print_j(void *ptr)
{
    (void)ptr;
    print("I am", " in j");
    return NULL;
}

int main(void)
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, print_i, NULL);
    pthread_create(&t2, NULL, print_j, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return EXIT_SUCCESS;
}
