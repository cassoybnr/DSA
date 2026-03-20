#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
}
    
void printList(struct Node* node){
        while(node != NULL) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("\n");
}
    
struct Node* reverseKGroup(struct Node* head, int k) {
    if(head == NULL || k == 1){
        return head;
    }
    
    int count = 0;
    struct Node* checker = head;
    while(checker != NULL && count < k) {
        checker = checker->next;
        count++;
    }
    
    if (count == k){
        struct Node* current = head;
        struct Node* prev = NULL;
        struct Node* next = NULL;
        
        for (int i = 0; i < k; i++){
            next = current ->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        if (current != NULL) {
            head->next = reverseKGroup(current, k);
        }
        return prev;
    }
    return head;
}

void freeList(struct Node* head){
    struct Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int size, k, data;
    struct Node* head = NULL;
    
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);
    
    printf("Enter k: ");
    scanf("%d", &k);
    
    for(int i = 1; i <= size; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }
    
    printf("Original List: ");
    printList(head);
    
    head = reverseKGroup(head, k);
    
    printf("Modified List: ");
    printList(head);
    
    freeList(head);
    
    return 0;
}