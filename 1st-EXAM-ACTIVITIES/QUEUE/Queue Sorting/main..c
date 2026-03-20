#include <stdio.h>

void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    
    int queue[size];
    
    printf("Enter %d integers to add to the queue: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &queue[i]); 
    }
    
    sortArray(queue, size);
    
    printf("Sorted queue:");
    for (int i = 0; i < size; i++) {
        printf(" %d", queue[i]); 
    }
    printf("\n");
    
    return 0;
}