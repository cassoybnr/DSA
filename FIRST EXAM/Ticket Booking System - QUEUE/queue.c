#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void enqueue(Queue *q, Customer c) {
    if(!isFull(q)){
    
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = c;
        q->count++;
        printf("%s added to queue\n", c.name);
    } else {
        printf("Queue is full\n");
    }
}

Customer dequeue(Queue *q) {
    Customer empty = {"", 0};
    if(!isEmpty(q)){
        Customer c = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        return c;        
    } else {
        printf("Queue is empty\n");
        return empty;
    }
}

void serveCustomer(Queue *q, int *tickets) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Customer c = dequeue(q);
    printf("Serving %s...\n", c.name);

    if(*tickets <= 0){
        printf("No tickets left for %s\n", c.name);
    } else if (*tickets >= c.ticketsRequested){
        *tickets -= c.ticketsRequested;
        printf("Booked %d tickets for %s\n", c.ticketsRequested, c.name);
    } else {
        printf("Only %d tickets left. Partial booking for %s\n", *tickets, c.name);
        *tickets = 0;
    }

    printf("Remaining tickets: %d\n\n", *tickets);
   
}