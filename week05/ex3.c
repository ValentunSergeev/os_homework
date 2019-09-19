//
// Created by valentun on 19.09.19.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#define BUFFER_MAX 10

#define PRINTING_PERIOD 1

pthread_t consumer_id, producer_id;

int buffer = 0;

pthread_mutex_t consumer_mutex, producer_mutex;
pthread_cond_t consumer_handler, producer_handler;

time_t consumer_timer = 0, producer_timer = 0;

int is_time_to_print(time_t previous_print_time) {
    int result =  time(NULL) - previous_print_time >= PRINTING_PERIOD;

    return result;
}

void *producer() {
    while (1) {
        if (buffer < BUFFER_MAX) {
            buffer++;

            if (is_time_to_print(producer_timer)) {
                printf("Producer, adding item, result: %d\n", buffer);
                fflush(stdout);

                time(&producer_timer);
            }
        } else {
            pthread_cond_signal(&consumer_handler);

            printf("Producer, go to sleep\n");

            pthread_cond_wait(&producer_handler, &producer_mutex);
        }
    }
}

void *consumer() {
    while (1) {
        if (buffer > 0) {
            buffer--;

            if (is_time_to_print(consumer_timer)) {
                printf("Consumer, removing item, result: %d\n", buffer);

                time(&consumer_timer);
                fflush(stdout);
            }
        } else {
            pthread_cond_signal(&producer_handler);

            printf("Consumer, go to sleep\n");

            pthread_cond_wait(&consumer_handler, &consumer_mutex);
        }
    }
}

int main() {
    pthread_create(&producer_id, NULL, producer, NULL);
    pthread_create(&consumer_id, NULL, consumer, NULL);

    pthread_join(consumer_id, NULL);
    pthread_join(producer_id, NULL);
}

#pragma clang diagnostic pop