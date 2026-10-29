#include <stdio.h>
#include <pthread.h>

#define TIMES_TO_COUNT 21000
#define NC "\033[0m"
#define YELLOW "\033[33m"
#define BYELLOW "\033[1;33m"
#define RED "\033[31m"
#define GREEN "\033[32m"

typedef struct s_counter {
    pthread_mutex_t count_mutex;
    unsigned int count;
} t_counter;

void *thread_routine(void *data)
{
    pthread_t tid = pthread_self();
    t_counter *counter = (t_counter *)data;
    unsigned int i = 0;

    pthread_mutex_lock(&counter->count_mutex);
    printf("%sThread [%lu]: counter starts at = %u.%s\n", YELLOW,
           (unsigned long)tid, counter->count, NC);
    pthread_mutex_unlock(&counter->count_mutex);
    while (i < TIMES_TO_COUNT) {
        pthread_mutex_lock(&counter->count_mutex);
        counter->count++;
        pthread_mutex_unlock(&counter->count_mutex);
        i++;
    }
    pthread_mutex_lock(&counter->count_mutex);
    printf("%sThread [%lu]: final counter = %u.%s\n", BYELLOW,
           (unsigned long)tid, counter->count, NC);
    pthread_mutex_unlock(&counter->count_mutex);
    return NULL;
}

int main(void)
{
    pthread_t tid1, tid2;
    t_counter counter;

    counter.count = 0;
    pthread_mutex_init(&counter.count_mutex, NULL);
    printf("Main: expected counter is %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);
    pthread_create(&tid1, NULL, thread_routine, &counter);
    printf("Main: creating first thread [%lu]\n", (unsigned long)tid1);
    pthread_create(&tid2, NULL, thread_routine, &counter);
    printf("Main: creating second thread [%lu]\n", (unsigned long)tid2);
    pthread_join(tid1, NULL);
    printf("Main: joined first thread [%lu]\n", (unsigned long)tid1);
    pthread_join(tid2, NULL);
    printf("Main: joined second thread [%lu]\n", (unsigned long)tid2);
    if (counter.count != (2 * TIMES_TO_COUNT)) {
        printf("%sMain: ERROR! Total counter is %u%s\n", RED, counter.count, NC);
    } else {
        printf("%sMain: OK. Total counter is %u%s\n", GREEN, counter.count, NC);
    }
    pthread_mutex_destroy(&counter.count_mutex);
    return 0;
}
