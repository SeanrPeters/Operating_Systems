#include <iostream>
#include <semaphore.h>

#ifndef DATA_H_
#define DATA_H_
struct shm
{
        sem_t isFull;
        sem_t sem;
        sem_t isEmpty;

        int buf[2];

        int pro;
        int con;
};
#endif
