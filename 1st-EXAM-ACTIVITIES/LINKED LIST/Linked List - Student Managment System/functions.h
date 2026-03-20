#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
typedef struct Student {
    char name[50];
    int studentID;
    float gpa;
    struct Student* next;
} Student;

// write your functions here

Student* createStudent(char name[], int studentID, float gpa) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->studentID = studentID;
    newNode->gpa = gpa;
    newNode->next = NULL;
    
    return newNode;
}

Student* insertStudent(Student* head, char name[], int studentID, float gpa){
    Student* newNode = createStudent(name, studentID, gpa);
    newNode->next = head;
    return newNode;
}

Student* deleteStudent(Student* head, int studentID){
    if(head == NULL){
        return head;
    }
    
    if(head->studentID == studentID){
        Student* temp = head;
        head = head->next;
        free(temp);
        printf("Student with ID %d removed.\n", studentID);
        return head;
    }
    
    Student* current = head;
    while (current->next != NULL && current->next->studentID != studentID){
        current = current->next;
    }
    
    if(current->next != NULL){
        Student *temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("Student with ID %d removed.\n", studentID);
    }
    return head;
}

void displayStudents(Student* head){
    printf("Student List:\n");
    Student* current = head;
    while (current != NULL) {
        printf("Name: %s, ID: %d, GPA: %.2f\n", current->name, current->studentID, current->gpa);
        current = current->next;
    }
}

void searchStudentByName(Student* head, char searchName[]){
    Student* current = head;
    int found = 0;
    
    while(current != NULL){
        if(strcmp(current->name, searchName) == 0){
            printf("Student found:\n");
            printf("Name: %s, ID: %d, GPA: %.2f\n", current->name, current->studentID, current->gpa);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

void freeList(Student* head){
    Student* current = head;
    Student* nextNode;
    
    while(current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}