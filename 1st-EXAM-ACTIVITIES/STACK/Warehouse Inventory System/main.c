#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayStack.h"

int main() {
    Stack stacks[3];
    for (int i = 0; i < 3; i++) {
        initialize(&stacks[i]);
    }

    int choice, id;

    while (1) {
        printf("\n--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1: {
                printf("Enter container ID to push: ");
                scanf("%d", &id);
                bool pushed = false;
                for (int i = 0; i < 3; i++) {
                    if (!isFull(&stacks[i])) {
                        push(&stacks[i], id);
                        printf("Container %d pushed successfully.\n", id);
                        pushed = true;
                        break;
                    }
                }
                if (!pushed) printf("All stacks are full!\n");
                break;
            }
            case 2: {
                bool popped = false;
                for (int i = 2; i >= 0; i--) {
                    if (!isEmpty(&stacks[i])) {
                        int val = pop(&stacks[i]);
                        printf("Container %d popped successfully.\n", val);
                        popped = true;
                        break;
                    }
                }
                if (!popped) printf("All stacks are empty!\n");
                break;
            }
            case 3: {
                printf("Enter container ID to search: ");
                scanf("%d", &id);
                bool found = false;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j <= stacks[i].top; j++) {
                        if (stacks[i].items[j] == id) {
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) printf("Container %d exists in the warehouse.\n", id);
                else printf("Container %d not found.\n", id);
                break;
            }
            case 4:
                for (int i = 0; i < 3; i++) {
                    printf("\n--- Stack %d ---\n", i + 1);
                    display(&stacks[i]);
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}