#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD 100

void *tarea(void *arg)
{
    (void)arg;
    return NULL;
}

static double segundos_transcurridos(struct timespec inicio, struct timespec fin)
{
    return (fin.tv_sec - inicio.tv_sec) + (fin.tv_nsec - inicio.tv_nsec) / 1000000000.0;
}

int main(void)
{
    pthread_t hilos[CANTIDAD];
    struct timespec inicio, fin;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    for (int i = 0; i < CANTIDAD; i++) {
        if (pthread_create(&hilos[i], NULL, tarea, NULL) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < CANTIDAD; i++) {
        pthread_join(hilos[i], NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &fin);

    printf("Tiempo para crear y esperar %d threads: %.6f segundos\n", CANTIDAD,
           segundos_transcurridos(inicio, fin));
    return EXIT_SUCCESS;
}
