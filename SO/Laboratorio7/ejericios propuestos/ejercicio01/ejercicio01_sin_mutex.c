#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NTHREADS 4
#define REPETICIONES 100000

/* Versión original para observar la condición de carrera. */
static int contador = 0;

static void *hilo(void *arg)
{
    const int incremento = *(const int *)arg;

    for (int j = 0; j < REPETICIONES; j++) {
        contador += incremento;
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
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("Sin mutex, contador = %d (esperado: %d)\n", contador, esperado);
    return EXIT_SUCCESS;
}
