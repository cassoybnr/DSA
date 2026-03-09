#include <stdio.h>

// Function header
int getNdx(int arr[], int n, int x);

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5;
    int x = 7;
    // Function call
    int index = getNdx(arr, n, x);
    printf("Index of first occurrence of %d: %d\n", x, index);
    return 0;
}

// Code of the Function
int getNdx(int arr[], int n, int x) {
    int i;
    for(i = 0; i < n && arr[i] != x; i++){
    }
    return (i != n) ? i : -1;
}