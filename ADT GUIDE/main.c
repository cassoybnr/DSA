#include <stdio.h>
#include <string.h>
#include "ArrayList.h"
#include "studtype.h"
#include "LinkedList.h"


int main (){
    StudPtr stud;
    LList * head = NULL;

    List arr;

    StudPtr stud1 = (StudPtr) malloc (sizeof(Studtype));
    if (stud1 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    StudPtr stud2 = (StudPtr) malloc (sizeof(Studtype));
    if (stud2 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    StudPtr stud3 = (StudPtr) malloc (sizeof(Studtype));
    if (stud3 == NULL){
        printf("memory alloc failed");
        exit(1);
    }
    StudPtr stud4 = (StudPtr) malloc (sizeof(Studtype));
    if (stud4 == NULL){
        printf("memory alloc failed");
        exit(1);
    }

    StudPtr unique = (StudPtr) malloc (sizeof(Studtype));
    if (unique == NULL){
        printf("memory alloc failed");
        exit(1);    
    }

    strcpy(stud1->name.FName, "Amber");
    strcpy(stud1->name.LName, "Apale");
    strcpy(stud1->course, "BSIT");
    stud1->age = 19;
    stud1->id = 1;
    
    strcpy(stud2->name.FName, "Casmir");
    strcpy(stud2->name.LName, "Ballesteros");
    strcpy(stud2->course, "BSIT");
    stud2->age = 20;
    stud2->id = 2;

    strcpy(stud3->name.FName, "Lana");
    strcpy(stud3->name.LName, "Pasculado");
    strcpy(stud3->course, "BAMA");
    stud3->age = 200;
    stud3->id = 3;
    
    strcpy(stud4->name.FName, "Mizzi");
    strcpy(stud4->name.LName, "Pomoy");
    strcpy(stud4->course, "BSBAYOT");
    stud4->age = 25;
    stud4->id = 67;

    strcpy(unique->name.FName, "Ian ");
    strcpy(unique->name.LName, "Lee");
    strcpy(unique->course, "BSIT");
    unique->age = 22;
    unique->id = 4;
    //array list

    printf("ARRAY LISTT\n");
    printf("------------------------------------\n");


    arr = initializeArr(arr);

    arr = insertPos(arr, stud1, 0);
    arr = insertPos(arr, stud2, 1);
    arr = insertPos(arr, stud3, 2);
    arr = insertSorted(arr, stud4);
    display(arr);
    arr = deletePos(arr, 1);
    display(arr);

    //linked list
    printf("\nLINKED LISTT\n");
    printf("------------------------------------\n");
    head = initializeLL();

    insertFirst(head, stud1);
    insertFirst(head, stud2);
    insertFirst(head, stud3);
    insertLast(head, stud4);
    insertPosLL(head, unique, 0);
    deleteLast(head);
    deleteStart(head);
    deletePosLL(head, 3);

    displayLL(head);

}