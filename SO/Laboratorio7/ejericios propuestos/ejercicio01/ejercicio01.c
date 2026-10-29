#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NTHREADS 4
#define REPETICIONES 100000

static int contador = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    int numero;
    int incremento;
} trabajo_t;

static void *hilo(void *arg)
{
    const trabajo_t *trabajo = arg;
    const int aporte = trabajo->incremento * REPETICIONES;

    printf("[Hilo %d | ID %lu] Incremento: %d, iteraciones: %d, aporte esperado: %d\n",
           trabajo->numero, (unsigned long)pthread_self(), trabajo->incremento,
           REPETICIONES, aporte);

    for (int j = 0; j < REPETICIONES; j++) {
        pthread_mutex_lock(&mutex);
        contador += trabajo->incremento;
        pthread_mutex_unlock(&mutex);
    }
    printf("[Hilo %d] Trabajo finalizado.\n", trabajo->numero);
    return NULL;
}

int main(void)
{
    pthread_t hilos[NTHREADS];
    trabajo_t trabajos[NTHREADS];
    const int esperado = REPETICIONES * (NTHREADS * (NTHREADS - 1) / 2);

    puts("=== Ejercicio 1: contador compartido protegido por mutex ===");
    printf("Threads: %d | Repeticiones por hilo: %d | Mutex: 1\n",
           NTHREADS, REPETICIONES);
    for (int i = 0; i < NTHREADS; i++) {
        trabajos[i] = (trabajo_t){.numero = i + 1, .incremento = i};
        int error = pthread_create(&hilos[i], NULL, hilo, &trabajos[i]);
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

    printf("Resultado final: contador = %d | Esperado = %d\n", contador, esperado);
    printf("Verificación: %s\n", contador == esperado ? "CORRECTA" : "ERROR");
    pthread_mutex_destroy(&mutex);
    return contador == esperado ? EXIT_SUCCESS : EXIT_FAILURE;
}
