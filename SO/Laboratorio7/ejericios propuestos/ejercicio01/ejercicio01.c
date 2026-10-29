#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NTHREADS 4
#define REPETICIONES 100000

int contador = 0;
pthread_mutex_t mutex;

void *hilo(void *arg)
{
    int i = *(int *)arg;

    for (int j = 0; j < REPETICIONES; j++) {
        pthread_mutex_lock(&mutex);
        contador = contador + i;
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    printf("Hilo %lu, contador = %d\n", (unsigned long)pthread_self(), contador);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(void)
{
    int i;
    int valores[NTHREADS];
    pthread_t thread[NTHREADS];

    if (pthread_mutex_init(&mutex, NULL) != 0) {
        return EXIT_FAILURE;
    }
    for (i = 0; i < NTHREADS; i++) {
        valores[i] = i;
        if (pthread_create(&thread[i], NULL, hilo, &valores[i]) != 0) {
            pthread_mutex_destroy(&mutex);
            return EXIT_FAILURE;
        }
    }
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(thread[i], NULL);
    }
    printf("Hilo principal, contador = %d (esperado: %d)\n", contador,
           REPETICIONES * (NTHREADS * (NTHREADS - 1) / 2));
    pthread_mutex_destroy(&mutex);
    return EXIT_SUCCESS;
}
