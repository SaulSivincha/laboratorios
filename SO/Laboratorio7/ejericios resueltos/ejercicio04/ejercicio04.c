#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t ml = PTHREAD_MUTEX_INITIALIZER;

void *Test(char *p, char *q)
{
    pthread_mutex_lock(&ml);
    printf("%s...\n", p);
    sleep(5);
    printf("%s...\n", q);
    sleep(5);
    pthread_mutex_unlock(&ml);
    return NULL;
}

void *T1(void *z)
{
    (void)z;
    return Test("Initialized", "1st Thread");
}

void *T2(void *z)
{
    (void)z;
    return Test("Initialized", "2nd Thread");
}

int main(void)
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, T1, NULL);
    pthread_create(&t2, NULL, T2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return EXIT_SUCCESS;
}
