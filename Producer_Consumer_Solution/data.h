// sean peters 4/6/2022
#include <iostream>
#include <semaphore.h>

#ifndef DATA_H_
#define DATA_H_
struct shm
{
        sem_t isFull;
        sem_t sem;
        sem_t isEmpty;

        int buf[2]; // buffer initialized to only 2 values max

        int pro; // an iterator for the producer buffer
        int con; // an iteratior for the consumer buffer
};
#endif
