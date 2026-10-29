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

typedef struct {
    contador_t *contador;
    int numero;
} trabajo_t;

static void *contar(void *arg)
{
    trabajo_t *trabajo = arg;

    printf("[Hilo %d | ID %lu] Inicia %d incrementos.\n", trabajo->numero,
           (unsigned long)pthread_self(), VECES_POR_HILO);

    for (int i = 0; i < VECES_POR_HILO; i++) {
        pthread_mutex_lock(&trabajo->contador->mutex);
        trabajo->contador->cuenta++;
        pthread_mutex_unlock(&trabajo->contador->mutex);
    }
    printf("[Hilo %d] Trabajo finalizado.\n", trabajo->numero);
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
    trabajo_t trabajos[NUM_HILOS];
    struct timespec inicio, fin;
    int error = pthread_mutex_init(&contador.mutex, NULL);
    if (error != 0) {
        fprintf(stderr, "pthread_mutex_init: %s\n", strerror(error));
        return EXIT_FAILURE;
    }

    puts("=== Ejercicio 2: cuatro threads con contador protegido ===");
    printf("Threads: %d | Incrementos por hilo: %d | Total esperado: %d\n",
           NUM_HILOS, VECES_POR_HILO, NUM_HILOS * VECES_POR_HILO);
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    for (int i = 0; i < NUM_HILOS; i++) {
        trabajos[i] = (trabajo_t){.contador = &contador, .numero = i + 1};
        error = pthread_create(&hilos[i], NULL, contar, &trabajos[i]);
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
    printf("Contador final: %u | Esperado: %u\n", contador.cuenta, esperado);
    printf("Tiempo de ejecución: %.6f segundos\n", segundos_transcurridos(inicio, fin));
    printf("Verificación: %s\n", contador.cuenta == esperado ? "CORRECTA" : "ERROR");
    pthread_mutex_destroy(&contador.mutex);
    return contador.cuenta == esperado ? EXIT_SUCCESS : EXIT_FAILURE;
}
