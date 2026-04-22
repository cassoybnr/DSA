#include <stdio.h>
#include "stack.h"

int main() {
    char str[MAX];
    Stack s;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);   // reads full line with spaces

    removeDuplicates(str, &s);
    displayStack(&s);

    return 0;
}