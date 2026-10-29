#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define CANTIDAD 100

static double segundos_transcurridos(struct timespec inicio, struct timespec fin)
{
    return (fin.tv_sec - inicio.tv_sec) +
           (fin.tv_nsec - inicio.tv_nsec) / 1000000000.0;
}

int main(void)
{
    struct timespec inicio, fin;
    int creados = 0;

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    for (int i = 0; i < CANTIDAD; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            break;
        }
        if (pid == 0) {
            _exit(EXIT_SUCCESS);
        }
        creados++;
    }
    for (int i = 0; i < creados; i++) {
        if (wait(NULL) == -1) {
            perror("wait");
            return EXIT_FAILURE;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &fin);

    printf("Tiempo para crear y esperar %d procesos: %.6f segundos\n", creados,
           segundos_transcurridos(inicio, fin));
    return creados == CANTIDAD ? EXIT_SUCCESS : EXIT_FAILURE;
}
