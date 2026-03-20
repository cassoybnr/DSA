Array Queue - Pharmacy Queueing System
by Edwin Bartlett

Create a C program for a pharmacy queueing system with two distinct queues: one for regular customers and another for priority
customers. The program should manage the flow of customers from arrival to service, prioritizing those in the priority queue.
The program should include the following essential features:

1. Upon arrival, a customer should be prompted to choose between entering the regular queue or the priority queue.

2. The system will automatically assign a unique queue number to each customer. This number should be sequential, starting
from 1.

3. There will be an option to call the next customer for service. The system must prioritize the priority queue at all times. If the
priority queue is not empty, the next customer called will always be from that queue. Only when the priority queue is empty
will the system call a customer from the regular queue.

Constraints:

1. You can only use the following functions to interact with the queues. Place these in arrayQueue.h:

o Queue* initialize();
o void enqueue(Queue* q, int value);
o int dequeue(Queue* q);
o bool isFull(Queue* q);
o bool isEmpty (Queue* q);
o void display(Queue* q);
