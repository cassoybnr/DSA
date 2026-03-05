#include <stdio.h>

#define SIZE 100

typedef struct
{
    int arr[SIZE];
    int top;
} Stack;

void init(Stack *S);
void push(Stack *S, int x);
void pop(Stack *S);
int top(Stack S);
int canSeeBoard(int column[], int length); // TODO

int main()
{
    int len;
    int col[SIZE];
    printf("How many students in a column: ");
    scanf("%d", &len);

    printf("Enter the heights of the students (in inches): \n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &col[i]);
    }
    printf("In this column, only %d student(s) can see the board.\n", canSeeBoard(col, len));
}

int canSeeBoard(int column[], int length)
{
    int canSee = 0;
    Stack S;
    init(&S);
    
    for (int i = 0; i < length; i++) {
        //stud can only see if they're taller than everyone pushed before them
        if(top(S) == -1 || column[i] > top(S)) { //is the line empty || am i the tallest in lines so far
            canSee++;
            push(&S, column[i]); //new plate on top of the stack
        }
    }
    
    return canSee; //number of studs that can see the board
}

void init(Stack *S)
{
    S->top = -1;
}

void push(Stack *S, int x)
{
    if (S->top != SIZE - 1)
    {
        S->arr[++(S->top)] = x;
    }
}

void pop(Stack *S)
{
    if (S->top != -1)
    {
        S->top--;
    }
}

int top(Stack S)
{
    return (S.top != -1) ? S.arr[S.top] : -1;
}
