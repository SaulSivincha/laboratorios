#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void *trythis(void *arg)
{
    (void)arg;
    unsigned long i = 0;
    pthread_mutex_lock(&lock);
    counter += 1;
    printf("\n Job %d has started\n", counter);
    for (i = 0; i < 0xFFFFFFFFUL; i++) {
    }
    printf("\n Job %d has finished\n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
    int i = 0;
    int error;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\nMutex initialization failed\n");
        return EXIT_FAILURE;
    }
    while (i < 2) {
        error = pthread_create(&tid[i], NULL, trythis, NULL);
        if (error != 0) {
            printf("\nThread cannot be created: [%s]\n", strerror(error));
            pthread_mutex_destroy(&lock);
            return EXIT_FAILURE;
        }
        i++;
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
    return EXIT_SUCCESS;
}
