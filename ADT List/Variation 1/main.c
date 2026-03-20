#include <stdio.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize (List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
    List L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    display(L);


    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count != MAX && position <= L.count){
        for(int i = L.count; i > position; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position] = data;
        L.count++;
        printf("Number %d was added at position %d\n", L.elem[position], position);
        return L;
    }
    printf("Invalid");
    return L;
}

List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L){
    printf("Displaying Array List\n");
    for(int i = 0; i < L.count; i++){
        printf("%d\n", L.elem[i]);
    }
}