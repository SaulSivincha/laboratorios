#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANIO 100
#define NUM_HILOS 4

typedef struct {
    const int *arreglo;
    int inicio;
    int fin;
    long suma_parcial;
} trabajo_t;

void *sumar_parte(void *arg)
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
        trabajos[i].arreglo = arreglo;
        trabajos[i].inicio = i * (TAMANIO / NUM_HILOS);
        trabajos[i].fin = (i + 1) * (TAMANIO / NUM_HILOS);
        pthread_create(&hilos[i], NULL, sumar_parte, &trabajos[i]);
    }

    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
        printf("Hilo %d: suma parcial = %ld\n", i + 1, trabajos[i].suma_parcial);
        suma_total += trabajos[i].suma_parcial;
    }

    printf("Suma total del arreglo: %ld\n", suma_total);
    return EXIT_SUCCESS;
}
