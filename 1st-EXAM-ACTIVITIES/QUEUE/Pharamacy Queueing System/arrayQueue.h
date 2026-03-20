#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

// write your functions here


Queue* initialize(){
    Queue* q = (Queue*) malloc (sizeof(Queue));
    
    q->front = 0;
    q->rear = -1;
    q->list.count = 0;
    
    return q;
}

bool isFull(Queue* q){
    //return ((q->rear + 2) % MAX) == q->front;
    return q->list.count == MAX;
}

bool isEmpty(Queue* q){
    return q->list.count == 0;
    //return ((q->rear + 1) % MAX) == q->front;
}

void enqueue(Queue* q, int value){
    if(!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->list.items[q->rear] = value;
        q->list.count++;
    } else {
        printf("Queue is full. Please try again later.\n");
    }
}

int dequeue(Queue* q){
    if(!isEmpty(q)){
        int data = q->list.items[q->front];
        
        q->list.count--;
        
        if(q->list.count == 0){ 
            q->front = 0;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return data;
    } else {
        printf("Queue is empty!");
        return -1;
    }
}


void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    while(1) {
        printf("%d ", q->list.items[i]);
        if(i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int front (Queue* q){
    return q->list.items[q->front];
}