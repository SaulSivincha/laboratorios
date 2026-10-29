#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_HILOS 4
#define VECES_POR_HILO 21000

typedef struct {
    pthread_mutex_t mutex;
    unsigned int cuenta;
} contador_t;

static void *contar(void *arg)
{
    contador_t *contador = arg;

    for (int i = 0; i < VECES_POR_HILO; i++) {
        pthread_mutex_lock(&contador->mutex);
        contador->cuenta++;
        pthread_mutex_unlock(&contador->mutex);
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
    contador_t contador = {.cuenta = 0};
    pthread_t hilos[NUM_HILOS];
    struct timespec inicio, fin;
    int error = pthread_mutex_init(&contador.mutex, NULL);
    if (error != 0) {
        fprintf(stderr, "pthread_mutex_init: %s\n", strerror(error));
        return EXIT_FAILURE;
    }

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    for (int i = 0; i < NUM_HILOS; i++) {
        error = pthread_create(&hilos[i], NULL, contar, &contador);
        if (error != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            for (int j = 0; j < i; j++) {
                pthread_join(hilos[j], NULL);
            }
            pthread_mutex_destroy(&contador.mutex);
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &fin);

    const unsigned int esperado = NUM_HILOS * VECES_POR_HILO;
    printf("Contador final: %u (esperado: %u)\n", contador.cuenta, esperado);
    printf("Tiempo de ejecución: %.6f segundos\n", segundos_transcurridos(inicio, fin));
    pthread_mutex_destroy(&contador.mutex);
    return contador.cuenta == esperado ? EXIT_SUCCESS : EXIT_FAILURE;
}
