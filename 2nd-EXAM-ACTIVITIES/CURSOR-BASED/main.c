#include <stdio.h>
#include "header.h"

void displayList(VHeap VH, List L) {
    int trav;

    for(trav = L; trav != -1; trav = VH.H[trav].next) {
        printf("%d -> ", VH.H[trav].elem);
    }

    printf("NULL\n");
}

int main(void){
    VHeap VH;
    List L = -1;

    initialize(&VH);

    insertFirst(&VH, &L, 10);
    insertFirst(&VH, &L, 20);
    insertFirst(&VH, &L, 30);

    displayList(VH, L);

    deleteFirst(&VH, &L);
    displayList(VH, L);

    return 0;
}