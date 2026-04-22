#ifndef STACK_H
#define STACK_H

#define MAX 10

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function declarations
void init(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

void removeDuplicates(char *str, Stack *s);
void displayStack(Stack *s);

#endif