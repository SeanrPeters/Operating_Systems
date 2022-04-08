//sean peters 4/6/2022
include "data.h"
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
        sleep(.1000); // makes it output fast while also introducing pauses
        int shared = shm_open("/sharedVal", O_RDWR, 0);
        shm_unlink("/sharedVal");
        struct shm *s = (struct shm *)mmap(NULL, sizeof(*s), PROT_READ | PROT_WRITE, MAP_SHA$

     
        for(int i = 0; i < 5; i++) // outputs five index's values assosiated with table
                {
                sem_wait(&s -> isFull);
                sem_wait(&s -> sem);

                s -> buf[s -> con] = rand()%5+1;

                std::cout << "Consumming Table..." << std::endl;
                std::cout << "Table[" << s -> con << "] has  " << s -> buf[s -> con] << "now" $

                s -> buf[s -> con] = -1;
                s -> con = (s -> con +1 ) % 2;

                sem_post(&s -> isEmpty);
                sem_post(&s -> sem);
                }
    return 0;
}


