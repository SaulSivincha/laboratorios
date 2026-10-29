#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

int total_words;
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;

void *count_words(void *f)
{
    char *filename = (char *)f;
    FILE *fp;
    int c, prevc = '\0';

    if ((fp = fopen(filename, "r")) != NULL) {
        while ((c = getc(fp)) != EOF) {
            if (!isalnum((unsigned char)c) && isalnum((unsigned char)prevc)) {
                pthread_mutex_lock(&counter_lock);
                total_words++;
                pthread_mutex_unlock(&counter_lock);
            }
            prevc = c;
        }
        if (isalnum((unsigned char)prevc)) {
            pthread_mutex_lock(&counter_lock);
            total_words++;
            pthread_mutex_unlock(&counter_lock);
        }
        fclose(fp);
    } else {
        perror(filename);
    }
    return NULL;
}

int main(int ac, char *av[])
{
    pthread_t t1, t2;
    if (ac != 3) {
        printf("usage: %s file1 file2\n", av[0]);
        return EXIT_FAILURE;
    }
    total_words = 0;
    pthread_create(&t1, NULL, count_words, av[1]);
    pthread_create(&t2, NULL, count_words, av[2]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Main thread with ID %lu reporting %5d total words\n",
           (unsigned long)pthread_self(), total_words);
    return EXIT_SUCCESS;
}
