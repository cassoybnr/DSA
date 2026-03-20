#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "types.h"

int main() {
    Queue* line = initialize();
    Queue* priority = initialize();
    
    int choice;
    int number = 1;
    
    while(1){
        printf("--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n2. Enter Priority Queue\n3. Call Next Customer\n4. Display Queues\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;
        
        switch (choice){
            case 1:
                if(!isFull(line)){
                    enqueue(line, number);
                printf("You have entered the Regular queue. Your number is %d.\n\n", number);
                    number++;
                } else {
                    printf("Regular queue is full. Please try again later.\n\n");
                }
                break;
                
            case 2:
                if(!isFull(priority)){
                    enqueue(priority, number);
                printf("You have entered the Priority queue. Your number is %d.\n\n", number);
                    number++;
                } else {
                    printf("Priority queue is full. Please try again later.\n\n");
                }
                break;
                
            case 3:
                if (!isEmpty(priority)) {
                    printf("Calling next customer from Priority Queue. Customer number: %d\n\n", front(priority));
                    dequeue(priority);
                } else if (!isEmpty(line)) {
                    printf("Calling next customer from Regular Queue. Customer number: %d\n\n", front(line));
                    dequeue(line);
                } else {
                    printf("Both queues are empty!\n\n");
                }
                break;
                
            case 4:
                printf("\n-- Current Queue Status --\n");
                printf("Regular Queue: ");
                display(line);
                printf("Priority Queue: ");
                display(priority);
                printf("\n");
                break;
                
            case 5:
                printf("Exiting program. Goodbye!\n");
                free(line);
                free(priority);
                return 0;
                
            default:
                printf("Invalid choice, try again.\n\n");
        }
    }
    return 0;
}