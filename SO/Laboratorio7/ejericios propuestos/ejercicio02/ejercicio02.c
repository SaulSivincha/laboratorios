#include <stdio.h>
#include <pthread.h>

// Cada thread cuenta TIMES_TO_COUNT veces
#define TIMES_TO_COUNT 21000
#define NUM_THREADS 4

#define NC "\033[0m"
#define YELLOW "\033[33m"
#define BYELLOW "\033[1;33m"
#define RED "\033[31m"
#define GREEN "\033[32m"

// Esta estructura contiene el recuento así como el mutex.
typedef struct s_counter {
    pthread_mutex_t count_mutex;
    unsigned int count;
} t_counter;

void *thread_routine(void *data)
{
    pthread_t tid;
    t_counter *counter;
    unsigned int i;

    tid = pthread_self();
    counter = (t_counter *)data;
    pthread_mutex_lock(&counter->count_mutex);
    printf("%sThread [%lu]: contador del thread empieza = %u.%s\n", YELLOW,
           (unsigned long)tid, counter->count, NC);
    pthread_mutex_unlock(&counter->count_mutex);

    i = 0;
    while (i < TIMES_TO_COUNT) {
        pthread_mutex_lock(&counter->count_mutex);
        counter->count++;
        pthread_mutex_unlock(&counter->count_mutex);
        i++;
    }

    pthread_mutex_lock(&counter->count_mutex);
    printf("%sThread [%lu]: Contador final = %u.%s\n", BYELLOW,
           (unsigned long)tid, counter->count, NC);
    pthread_mutex_unlock(&counter->count_mutex);
    return NULL;
}

int main(void)
{
    pthread_t tid[NUM_THREADS];
    t_counter counter;

    counter.count = 0;
    pthread_mutex_init(&counter.count_mutex, NULL);
    printf("Main: el contador esperado es %s%u%s\n", GREEN,
           NUM_THREADS * TIMES_TO_COUNT, NC);

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&tid[i], NULL, thread_routine, &counter) != 0) {
            return 1;
        }
        printf("Main: Creando el thread %d [%lu]\n", i + 1,
               (unsigned long)tid[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(tid[i], NULL);
        printf("Main: adiciona el thread %d [%lu]\n", i + 1,
               (unsigned long)tid[i]);
    }

    if (counter.count != (NUM_THREADS * TIMES_TO_COUNT)) {
        printf("%sMain: ERROR ! Total contador es %u%s\n", RED, counter.count, NC);
    } else {
        printf("%sMain: OK. Total contador es %u%s\n", GREEN, counter.count, NC);
    }
    pthread_mutex_destroy(&counter.count_mutex);
    return 0;
}
