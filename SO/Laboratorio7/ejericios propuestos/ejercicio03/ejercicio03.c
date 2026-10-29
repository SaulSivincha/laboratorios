#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_HILOS 10
#define INCREMENTOS 10000000

static int correos = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *incrementar(void *arg)
{
    (void)arg;
    for (int i = 0; i < INCREMENTOS; i++) {
        pthread_mutex_lock(&mutex);
        correos++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

static double segundos_transcurridos(struct timespec inicio, struct timespec fin)
{
    return (fin.tv_sec - inicio.tv_sec) +
           (fin.tv_nsec - inicio.tv_nsec) / 1000000000.0;
}

int main(void)
{
    pthread_t hilos[NUM_HILOS];
    struct timespec inicio, fin;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    for (int i = 0; i < NUM_HILOS; i++) {
        int error = pthread_create(&hilos[i], NULL, incrementar, NULL);
        if (error != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            for (int j = 0; j < i; j++) {
                pthread_join(hilos[j], NULL);
            }
            pthread_mutex_destroy(&mutex);
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &fin);

    const int esperado = NUM_HILOS * INCREMENTOS;
    printf("Número de correos: %d (esperado: %d)\n", correos, esperado);
    printf("Tiempo de ejecución: %.6f segundos\n", segundos_transcurridos(inicio, fin));
    pthread_mutex_destroy(&mutex);
    return correos == esperado ? EXIT_SUCCESS : EXIT_FAILURE;
}
