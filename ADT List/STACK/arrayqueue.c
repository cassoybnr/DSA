Queue * initialize(){
    Queue * Q = (Queue*)malloc(sizeof(Queue));
    Q->list.count = 0;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

bool isFull(Queue * Q){
    return Q->front == MAX - 1;
}

bool isEmpty(Queue * Q){
    return Q->front == -1;
}

void enqueue(Queue * Q, int value){
    if(!isFull(Q)){
        if(!isEmpty(Q)){
            Q->rear = (Q->rear + 1) % MAX;
        } else {
            Q->front = 0;
            Q->rear = 0;
        }
        Q->list.items[Q->rear] = value;
        Q->list.count++;
    }
}

void dequeue(Queue * Q){
    if(!isEmpty(Q)){
        int num = Q->list.items[Q->front];
        if(Q->list.count == 1){}
    }
}