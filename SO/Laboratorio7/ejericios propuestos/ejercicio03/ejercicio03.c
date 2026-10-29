#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10

int mails = 0;
pthread_mutex_t mutex;

void *routine(void *arg)
{
    (void)arg;
    for (int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void)
{
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, routine, NULL) != 0) {
            return i + 1;
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            return NUM_THREADS + i + 1;
        }
    }
    pthread_mutex_destroy(&mutex);
    printf("Numero de mails: %d\n", mails);
    return 0;
}
