#include <stdio.h>
#include <stdlib.h>
#include "given.h"

// write your function here

void bubbleSortLinkedList(Node* head){
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;
    
    if (head == NULL || head->next == NULL){
        return;
    }
    do {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if(ptr1->data > ptr1->next->data){
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}