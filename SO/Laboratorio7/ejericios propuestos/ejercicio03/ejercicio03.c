#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *mostrar_id(void *arg)
{
    const pthread_t *id_principal = arg;
    pthread_t id_actual = pthread_self();

    printf("ID dentro del thread creado: %lu\n", (unsigned long)id_actual);
    printf("¿Es el mismo que el thread principal? %s\n",
           pthread_equal(*id_principal, id_actual) ? "Sí" : "No");
    return NULL;
}

int main(void)
{
    pthread_t hilo;
    pthread_t id_principal = pthread_self();
    printf("ID del thread principal (main): %lu\n", (unsigned long)id_principal);

    int error = pthread_create(&hilo, NULL, mostrar_id, &id_principal);
    if (error != 0) {
        fprintf(stderr, "pthread_create: %s\n", strerror(error));
        return EXIT_FAILURE;
    }
    pthread_join(hilo, NULL);
    return EXIT_SUCCESS;
}
