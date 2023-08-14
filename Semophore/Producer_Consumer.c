#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define prod 10
int buffer[BUFFER_SIZE], in = 0, out = 0;
sem_t empty, full, mutex;

void *producer(void *arg)
{
    int item = 1;

    while (item<=prod)
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        // printf("Producer : Insert Item %d\n",buffer[in]);
        printf("Producer %d: Insert Item %d at %d\n", *((int *)arg),buffer[in],in);
        in = (in+1)%BUFFER_SIZE;
        item++;

        sem_post(&mutex);
        sem_post(&full);

        sleep(rand() % 2);

    }

    return NULL;
}

void *consumer(void *arg)
{
    int item,cons=0;
    while (cons<prod)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        // printf("Consumer : Remove Item %d\n",item);
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)arg),item, out);
        out = (out+1)%BUFFER_SIZE;
        cons++;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(rand() % 2);
    }

    return NULL;
}

int main()
{
    // pthread_t producer_thread, consumer_thread;
    pthread_t p[5], c[5];
    int a[5] = {1, 2, 3, 4, 5};

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // pthread_create(&producer_thread, NULL, producer, NULL);
    // pthread_create(&consumer_thread, NULL, consumer, NULL);

    // pthread_join(producer_thread, NULL);
    // pthread_join(consumer_thread, NULL);

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&p[i], NULL, producer, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&c[i], NULL, consumer, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(p[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(c[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}
