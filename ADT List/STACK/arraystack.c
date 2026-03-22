//ARRAY
Stack * initialize(){
    Stack * s (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack * s){
    return s->top == MAX - 1;
}

bool isEmpty(Stack * s){
    return s->top == -1;

}

void push(Stack * s, int value){
    if(!isFull(s)){
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack * s){
    if(!isEmpty(s)){
        int num = s->items[s->top];
        s->top--;
        return num;
    } else {
        printf("\nCurrent Stack is empty\n");
    }
}

int peek(Stack * s){
    if(!isEmpty(s)){
        return s->items[s->top];
    } else {
        return -1;
    }
}

void display(Stack * s){
    if(!isEmpty(s)){
        printf("\nStack\n");
        for(int i = 0; i <=s->top; i++){
            printf("Index: %d: %d\n", i, s->items[i]);
        }
    }else{
        printf("\nList is Empty\n");
    }
}
