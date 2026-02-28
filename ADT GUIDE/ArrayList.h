#ifndef ArrayList_H
#define ArrayList_H
#include <stdio.h>
#include <stdlib.h>
#include "studtype.h"
#define MAX 10

typedef struct {
    StudPtr elem[MAX];
    int count;
}List;

//Initialize the List
List initialize(List L){
    count = 0;
    return L;
}

List insertPos(List L, StudPtr data, int position){
    int i;

    if(position > L.count || position < 0){
        printf("invalid positon");
    } else if (L.count == MAX) {
        printf("puno na");
    } else {
        for(i = L.count; i >= position; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.count++;
        L.elem[position] = data;
    }
    return 1;
}

List deletePost(List L, int position){
    int i;
    if (positon < 0 || position >= L.count){
        printf("Invalid position");
    } else {
        for (i = position; i < L.count - 1; i++){
            L.elem[i] = L.elem [i - 1];
        }
        L.count--;
        printf("\ndata has been deleted at position %d\n\n", position);
    }
    return 1;
}


List locate(List L, StudPtr data){
    int i, j = -1;

    for (i = 0; i < L.count && j == -1; i++){
        if(L.elem[i]->id == data->id){
            j = i;
        }
    }
    return i;
}


List inserSorted (List L, StudPtr data){
    int i, pos = L.count;
    if (L.count == MAX){
        printf("The array is already full.");
    } else {
        for (i = 0; i < L.count && L.elem[i]->id < data->id; i++){
            pos++;
        }
        pos = i;

        for (i = L.count; i > pos; i--){
            L.elem[i] = L.elem[i - 1];
        }

        L.count++;
        L.elem[pos] = data;
    }
    return 1;
}

void display(List L){
    int i;
    printf("%-15s %-15s %-10s %-5s %-5s\n", "First Name", "Last Name", "Course", "Yr", "ID");
    printf("--------------------------------------------------------------");

    for(i = o; i < L.count; i++){
        printf("%-15s %-15s %-10s %-5s %-5s\n"
            L.elem[i]->name.FName,
            L.elem[i]->name.LName,
            L.elem[i]->course,
            L.elem[i]->age,
            L.elem[i]->id)
    }
}

#endif