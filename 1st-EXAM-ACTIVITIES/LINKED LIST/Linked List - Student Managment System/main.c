#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    // complete the main function
    Student* head = NULL;
    int choice;
    char name[50];
    int id;
    float gpa;
    
    printf(" \n");
    while (1) {
        printf("Student Management System:\n");
        printf("1. Enroll Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf(" %[^\n]", name);
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student GPA: ");
                scanf("%f", &gpa);
                head = insertStudent(head, name, id, gpa);
                printf("\n");
                break;
            case 2:
                printf("Enter student ID to remove: ");
                scanf("%d", &id);
                head = deleteStudent(head, id);
                printf("\n");
                break;
                
            case 3: 
                displayStudents(head);
                printf("\n");
                break;
                
            case 4:
                printf("Enter student name to search: ");
                scanf(" %[^\n]", name);
                searchStudentByName(head, name);
                printf("\n");
                break;
                
            case 5: 
                printf("Exiting program,,.\n");
                freeList(head);
                return 0;
                
            default:
            printf("Invalid choice. Please try again.\n\n");
            
        }
    }
    


    return 0;
}