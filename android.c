#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void* thread_function(void* arg) {
    sem_wait(&mutex);
    printf("Thread %d: Running\n", *(int*)arg);
    sem_post(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);
    return 0;
}