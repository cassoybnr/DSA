#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void initialize(VHeap *VH) {
    for(int i = 0; i < MAX - 1; i++){
        VH->H[i].next = i + 1;
    }
    VH->H[MAX - 1].next = -1;
    VH->avail = 0;
}

int allocSpace(VHeap *VH) {
    int space = VH->avail;
    
    if(space != -1){
        VH->avail = VH->H[space].next;
    }
    return space;
}

void deallocSpace(VHeap *VH, int index) {
    VH->H[index].next = VH->avail;
    VH->avail = index;
    
}

void insertFirst(VHeap *VH, List *L, int elem) {
    int newNode = allocSpace(VH);
    
    if(newNode != -1){
        VH->H[newNode].elem = elem;
        VH->H[newNode].next = *L;
        *L = newNode;
    } else {
        printf("No available space\n");
    }
}

void deleteFirst(VHeap *VH, List *L) {
    if(*L != -1){
        int temp = *L;
        *L = VH->H[temp].next;
        deallocSpace(VH, temp);
    } else {
        printf("List is empty\n");
    }
}