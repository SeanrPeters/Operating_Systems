# Operating_Systems- Banker’s Algorithm for deadlock avoidance

The Banker's Algorithm functions by having a starting state and then running simpulations
inorder to find a safe state. When a safe state is finally found, it goes into the nect assignment 
in a "safe sequence". When all of the processes are in this sequence, the algorithm is completed and the
program will output the safe sequence. 

Example:
Input: 

3, 3, 2

0, 7, 1, 5, 0, 3

2, 3, 0, 2, 0, 2

3, 9, 0, 0, 2, 2

2, 2, 1, 2, 1, 2

0, 4, 0, 3, 2, 3


Output:
The safe sequence would be:
P1 > P3 > P4 > P0 > P2

Use this to run code:
g++ BankersAlgorithm.cpp -o BankersAlgorithm
./BankersAlgorithm

