Problem:

The producer generates items and puts items onto the table. The consumer will pick up items.
The table can only hold two items at the same time. When the table is complete, the producer will wait. When there are no items, 
the consumer will wait. We use semaphores to synchronize producer and consumer.  
Mutual exclusion should be considered. We use threads in the producer program and consumer program. 
Shared memory is used for the “table”.

Solution:
  The .c source files enter a shared memory. If critical section is unlocked and the buffer is also empty then the consumer or the producer 
can enter the critical section. The critical section is only unlocked if neither of the programs are currently in it. This ensures that only one
can enter at a given time. When in the critical selection the .c file will print the value assosiated with the buffers index. Then, the index is decremented
until it is empty. The file ( consumer or producer) will then leave the critical selection. This process is committed a total of 5 times for each file (10 times in total).

Use This To Compile:
 g++ producer.c -pthread -lrt -o producer
 g++ consumer.c -pthread -lrt -o consumer
 ./producer & ./consumer &

Example:
 g++ producer.c -pthread -lrt -o producer
 g++ consumer.c -pthread -lrt -o consumer
 ./producer & ./consumer &
[1] 3820020
[2] 3820021
[speter61@wasp Assignment1]$ Producing Table....
 Table[0] has 4 now
Producing Table....
 Table[1] has 2 now
Consumming Table...
Table[0] has  4now
Consumming Table...
Table[1] has  2now
Producing Table....
 Table[0] has 3 now
Producing Table....
 Table[1] has 1 now
Consumming Table...
Table[0] has  3now
Consumming Table...
Table[1] has  1now
Producing Table....
 Table[0] has 4 now
Consumming Table...
Table[0] has  4now
