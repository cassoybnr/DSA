#include <stdio.h>
#include <stdlib.h>

int* get_even(int source[], int n);

int main(){
    int source[5] = {2,4,16,28,40};
    int n = sizeof(source) / sizeof(source[0]);

    int* resultPtr = get_even(source, n);
    
    if(resultPtr == NULL){
        printf("No even numbers found.\n");
    } else {
        printf("Even numbers found:\n");
        for(int i = 0; resultPtr[i] != -1; i++){
            printf("%d ", resultPtr[i]);
        }
        printf("\n");
        free(resultPtr);
    }
    return 0;
}

int* get_even(int source[], int n){
    int count = 0;

    for (int i = 0; i < n; i++) {
        if(source[i] % 2 == 0) {
            count++;
        }
    }

    if (count == 0) {
        return NULL;
    }

    int* result = (int*)malloc((count + 1) * sizeof(int));

    int j = 0;
    for (int i = 0; i < n; i++){
        if (source[i] % 2 == 0){
            result[j] = source[i];
            j++;
        }
    }
    result[j] = -1;  // Sentinel value to mark the end
    return result;
}

