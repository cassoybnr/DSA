#include <stdio.h>
#include <stdlib.h>


//Node structure
stuct Node {
    int data;
    struct Node* next;
};

//Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return NULL; //allocation failed fah
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//Traverse/ print
void printList(struct Node*head) {
    struct Node* trav = head;
    while (trav != NULL){ //ug dili null si trav (last node) continue lang pre
        printf("%d", trav->data); //print the data ng node!!
        trav = trav->next; //move on na tau onto the next node parehh
    }
    printf("\n"); //newline
}
//Key take away hurhur is that si trav lang ang mo lihok while si head same ra si anteh.

//Insertion at the beginning w/o traversal
void insertFront(struct Node** head, int value){
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    newNode->next = *head;
    *head = newNode;
}
//The double pointer struct Node** head allows us to update the real head from the inside of the function

//Inserstion at end w/ traversal
void insertEnd(struct Node** head, int value){
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    if (*head == NULL){
        *head = newNode;    //empty list scenario
        return;
    }

    struct Node* trav = *head;
    while (trav->next != NULL){     //stop at the last node
        trav = trav->next;
    }
    trav->next = newNode;
}
//If the list is empty, no need to traverse. Just set the new node as the head
//If you want to land on the last node then use trav where the next node i not equal to null B)