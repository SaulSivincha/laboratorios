#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO 100
#define NUM_HILOS 4

typedef struct {
    const int *arreglo;
    int inicio;
    int fin;
    long suma_parcial;
} trabajo_t;

static void *sumar_parte(void *arg)
{
    trabajo_t *trabajo = arg;
    trabajo->suma_parcial = 0;
    for (int i = trabajo->inicio; i < trabajo->fin; i++) {
        trabajo->suma_parcial += trabajo->arreglo[i];
    }
    return NULL;
}

int main(void)
{
    int arreglo[TAMANIO];
    pthread_t hilos[NUM_HILOS];
    trabajo_t trabajos[NUM_HILOS];
    long suma_total = 0;

    for (int i = 0; i < TAMANIO; i++) {
        arreglo[i] = i + 1;
    }

    for (int i = 0; i < NUM_HILOS; i++) {
        trabajos[i] = (trabajo_t){
            .arreglo = arreglo,
            .inicio = i * (TAMANIO / NUM_HILOS),
            .fin = (i + 1) * (TAMANIO / NUM_HILOS),
            .suma_parcial = 0,
        };
        int error = pthread_create(&hilos[i], NULL, sumar_parte, &trabajos[i]);
        if (error != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(error));
            for (int j = 0; j < i; j++) {
                pthread_join(hilos[j], NULL);
            }
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
        printf("Hilo %d: suma parcial = %ld\n", i + 1, trabajos[i].suma_parcial);
        suma_total += trabajos[i].suma_parcial;
    }
    printf("Suma total del arreglo: %ld\n", suma_total);
    return suma_total == 5050 ? EXIT_SUCCESS : EXIT_FAILURE;
}
