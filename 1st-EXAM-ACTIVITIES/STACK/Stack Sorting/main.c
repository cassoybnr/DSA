#include <stdio.h>

#define MAX 100

int inputStack[MAX], auxStack[MAX];
int topInput = -1, topAux = -1;

void pushInput(int val) { inputStack[++topInput] = val; }
int popInput() { return inputStack[topInput--]; }
int peekInput() { return inputStack[topInput]; }

void pushAux(int val) { auxStack[++topAux] = val; }
int popAux() { return auxStack[topAux--]; }
int peekAux() { return auxStack[topAux]; }

void sortStack() {
    while (topInput != -1) {
        int temp = popInput();

        while (topAux != -1 && peekAux() > temp) {
            pushInput(popAux());
        }

        pushAux(temp);
    }
}

int main() {
    int n, val;

    printf("Enter the number of elements in the stack: ");
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        pushInput(val);
    }

    sortStack();

    printf("Sorted Stack: ");
    while (topAux != -1) {
        printf("%d ", popAux());
    }
    printf("\n");

    return 0;
}