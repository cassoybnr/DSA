#include <stdio.h>
#include "stack.h"

int peek(Stack *s) {
    if(isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
}

void removeDuplicates(char *str, Stack *s) {
    init(s);
    
    for(int i = 0; str[i] != '\0'; i++){
        char current = str[i];
        
        if(isEmpty(s) || peek(s) != current) {
            push(s, current);
        } else {
            pop(s);
        }
    }
}
