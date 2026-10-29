#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NTHREADS 4
#define REPETICIONES 100000

static int contador = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *hilo(void *arg)
{
    const int incremento = *(const int *)arg;

    for (int j = 0; j < REPETICIONES; j++) {
        pthread_mutex_lock(&mutex);
        contador += incremento;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void)
{
    pthread_t hilos[NTHREADS];
    int incrementos[NTHREADS];
    const int esperado = REPETICIONES * (NTHREADS * (NTHREADS - 1) / 2);

    for (int i = 0; i < NTHREADS; i++) {
        incrementos[i] = i;
        int error = pthread_create(&hilos[i], NULL, hilo, &incrementos[i]);
        if (error != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            for (int j = 0; j < i; j++) {
                pthread_join(hilos[j], NULL);
            }
            pthread_mutex_destroy(&mutex);
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Hilo principal, contador = %d (esperado: %d)\n", contador, esperado);
    pthread_mutex_destroy(&mutex);
    return contador == esperado ? EXIT_SUCCESS : EXIT_FAILURE;
}
