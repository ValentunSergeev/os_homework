//
// Created by valentun on 19.09.19.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 5

int thread_ids[THREAD_COUNT];

void * thread_function(int i) {
    printf("Thread %d, created at %d\n", (int) pthread_self(), i);

    pthread_exit(NULL);
}

int main() {
    for (int i = 0; i < THREAD_COUNT; ++i) {
        pthread_create((pthread_t *) &thread_ids[i], NULL, thread_function, i);

        printf("Mаin (%d) thread. Created a new (%d) thread\n", (int) pthread_self(), thread_ids[i]);

        sleep(1);
    }
}