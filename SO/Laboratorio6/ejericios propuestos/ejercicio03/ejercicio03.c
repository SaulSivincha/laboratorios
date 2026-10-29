#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *mostrar_id(void *arg)
{
    pthread_t *id_principal = arg;
    pthread_t id_actual = pthread_self();

    printf("ID dentro del thread creado: %lu\n", (unsigned long)id_actual);
    printf("¿Es el mismo que el thread principal? %s\n",
           pthread_equal(*id_principal, id_actual) ? "Si" : "No");
    return NULL;
}

int main(void)
{
    pthread_t hilo;
    pthread_t id_principal = pthread_self();

    printf("ID del thread principal (main): %lu\n", (unsigned long)id_principal);
    if (pthread_create(&hilo, NULL, mostrar_id, &id_principal) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }
    pthread_join(hilo, NULL);
    return EXIT_SUCCESS;
}
