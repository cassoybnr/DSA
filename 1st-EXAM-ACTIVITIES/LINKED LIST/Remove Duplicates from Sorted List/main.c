#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL){
        last = last->next;
    }
    
    last->next = new_node;
}

void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* next_next;
    
    if (current == NULL){
        return;
    }
    
    while (current->next != NULL){
        if(current->data == current->next->data){
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}

void printList(struct Node* node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(struct Node* head){
    struct Node* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int size, data;
    struct Node* head = NULL;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);
    
    for(int i = 1; i <= size; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }
    
    removeDuplicates(head);
    
    printf("Linked list after removing duplicates: ");
    printList(head);
    
    freeList(head);
}