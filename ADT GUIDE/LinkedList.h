#ifndef LinkedList_H
#define LinkedList_H

#include <stdio.h>
#include <stdlib.h>
#include "studtype.h"

typedef struct node {
    StudPtr data;
    struct node* next;
}Node;

typedef struct {
    Node *head;
    int count;
}LList;

LList * initialize (){
    LList* L = (LList*)malloc(sizeof(LList));
    if(L == NULL){
        printf("Memory allocation failed.");
        return NULL;
    } else {
        L->head = NULL;
        L->count = 0;
    }

    return L;
}

void empty(LList * L){
    Node* temp;
    while (L->head != NULL){
        temp = L->head;
        L->head = L->head->next;
        free(temp);
    }
    L->count = 0;
}

void insertFirst(LList * L, StudPtr data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation Failed");
    } else {
        newNode->data = data;
        newNode->next = L->head;
        L->head = newNode;
        L->count++;
    }
}

void insertLast(LList* L, StudPtr data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("memory allocation failed");
    } else {
        newNode->data = data;
        newNode->next = NULL;
        if(L->head == NULL){
            L->head = newNode;
            L->count++;
        } else {
            Node* current;
            for (current = L->head; current->next != NULL; current = current->next){}
            
            current->next = newNode;
            L->count++;
        }
    }
}

void insertPosLList(LList * L, StudPtr data, int index){
    if(index > L->count){
        printf("Index invalid");
    } else if(index == 0){
        insertFirst(L, data);
    } else if (index == L->count){
        insertLast(L, data);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if(newNode == NULL){
            printf("memory allocation failed.");
        } else {
            newNode->data = data;
            Node* current;
            int i = 0;
            for(current = L->head; current->next != NULL && i < index - 1; current = current->next){
                i++;
            }
            newNode->next = current->next;
            current->next = newNode;
            L->count++;
        }
    }
}

void deleteStart(LList * L){
    if(L->head == NULL){
        printf("Linked List is empty");
    } else {
        Node* current = L->head;
        L->head = current->next;
        free(current);
        L->count--;
        printf("The first node has been deleted.\n");
    }
}

void deleteLast(LList* L){
    if(L->head == NULL){
        printf("Linked List is empty");
    } else {
        if(L->head->next == NULL){
            free(L->head);
        } else {
            Node* current;
            for(current = L->head; current->next != NULL; current = current->next){}
            free(current->next);
            current->next = NULL;
            printf("The last node has been deleted.\n");
        }
        L->count--;
    }
}

void deletePosLL(LList* L, int index){
    if(index < 0 || index >= L->count){
        printf("Invalid position\n\n");
    } else {
        if (index == 0){
            deleteStart(L);
        } else if (index == L->count - 1){
            deleteLast(L);            
        } else {
            Node* current;
            int i;
            for(i = 0; i < index - 1; i++){
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;

            free(temp);
            L->count--;
            printf("Node has been successfully deleted at position %d\n\n", index);
        }
    }
}

StudPtr retrieve(LList* L, int index){
    if (index > L->count){
        printf("Invalid Index");
    } else {
        Node* current;
        int i = 0;
        for(current = L->head; current->next != NULL && i <= index; current = current->next){
            i++;
        }
        return current->data;
    }
}

int locateLList(LList *L, StudPtr data){
    Node* temp;
    int post = 1, i = 0, retval = -1;
    for(temp = L->head; temp != NULL && data != temp->data; temp = temp->next){
        i++;
    }
        if(temp != NULL){
            retval = i;
        } else {
            printf("data not found");
        }
        return retval;
}

void displayLList(LList* L){
    Node* temp;
    printf("%-15s %-15s %-10s %-5s %-5s\n", "First Name", "Last Name", "Course", "Yr", "ID");
    printf("----------------------------------------------------------\n");
    for (temp = L->head; temp != NULL; temp = temp->next) {
        printf("%-15s %-15s %-10s %-5d %-5d\n",
            temp->data->name.FName,
            temp->data->name.LName,
            temp->data->course,
            temp->data->age,
            temp->data->id);
    }
}

#endif