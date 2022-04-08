
#include "data.h"
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
         int shared = shm_open("/sharedVal", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
          struct shm *s = (struct shm *)mmap(NULL, sizeof(*s),PROT_READ | PROT_WRITE,MAP_SHARED,shared,0);

         if(ftruncate(shared,sizeof(struct shm))==-1)
                {
                 shm_unlink("/sharedVal");
                 return -1;
                }

         if(sem_init(&s->isEmpty, 1, 2)||sem_init(&s->isFull, 1, 0)||sem_init(&s->sem, 1, 1) == -1)
                {
                shm_unlink("/sharedVal"); //clears shared mem obj
                return -1;
                }

        for(int i = 0; i < 5; i++)
                 {
                sem_wait(&s->isEmpty);
                sem_wait(&s->sem);

                s -> buf[s -> pro] = rand()%5+1;

                std::cout << "Producing Table...." << std::endl;
                std::cout << " Table[" << s->pro <<"] has " << s->buf[s->pro]<< " now" << std::endl;

                s -> pro = (s -> pro +1 ) % 2;

                sem_post(&s -> sem);
                sem_post(&s -> isFull);
    }


    return 0; 
}
    
