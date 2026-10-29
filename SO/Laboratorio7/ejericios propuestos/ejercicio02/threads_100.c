#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CANTIDAD 100

static void *tarea(void *arg)
{
    (void)arg;
    return NULL;
}

static double segundos_transcurridos(struct timespec inicio, struct timespec fin)
{
    return (fin.tv_sec - inicio.tv_sec) +
           (fin.tv_nsec - inicio.tv_nsec) / 1000000000.0;
}

int main(void)
{
    pthread_t hilos[CANTIDAD];
    int creados = 0;
    struct timespec inicio, fin;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    for (int i = 0; i < CANTIDAD; i++) {
        int error = pthread_create(&hilos[i], NULL, tarea, NULL);
        if (error != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            break;
        }
        creados++;
    }
    for (int i = 0; i < creados; i++) {
        pthread_join(hilos[i], NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &fin);

    printf("Tiempo para crear y esperar %d threads: %.6f segundos\n", creados,
           segundos_transcurridos(inicio, fin));
    return creados == CANTIDAD ? EXIT_SUCCESS : EXIT_FAILURE;
}
