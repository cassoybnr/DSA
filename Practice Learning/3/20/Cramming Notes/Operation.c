void insertFirst(List *list, int data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode = next = list->head; //point to old head
    list->head = newNode; //new node is the new head
    list->count++;
}

void deleteStart(List *list){
    Node *temp = list->head; //save old head
    list->head = list->head->next; //skip over it
    free(temp); // free the memory
    list->count--;
}

Node *current = list->head;
while (current != NULL){
    printf("%d", current->data);
    current = current->next; //move forward
}



