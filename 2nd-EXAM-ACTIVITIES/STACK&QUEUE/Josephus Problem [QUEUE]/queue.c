#include <stdio.h>
#include "queue.h"

void rotate(CircularQueue *q) {
    if (isEmpty(q)) return;

    int temp = dequeue(q);
    enqueue(q, temp);
}

int josephus(int n, int k) {
    CircularQueue q;
    init(&q);

    // enqueue people 1 to n
    for (int i = 1; i <= n; i++) {
        enqueue(&q, i);
    }

    while (q.list.count > 1) {
        // rotate k-1 times
        for (int i = 0; i < k - 1; i++) {
            rotate(&q);
        }

        // print eliminated before removing
        int eliminated = dequeue(&q);
        printf("Eliminated: %d\n", eliminated);
    }

    // last remaining person
    return dequeue(&q);
}