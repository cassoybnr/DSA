#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
    char LName[30];
    char FName[30];
    char MI;
}Name;

typedef struct{
    Name name;
    char course[8];
    int id;
    int age;
}Studtype, *StudPtr;

typedef struct {
    StudPtr elem[MAX];
    int count;
}List;


List initializeArr(List L);
List insertPos(List L, StudPtr data, int position);
List deletePos(List L, int position);
List locate(List L, StudPtr data);
List insertSorted (List L, StudPtr data);
void displayArr(List L);

int main(){
    StudPtr stud;
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

}


List initializeArr(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, StudPtr data, int position){
    int i;

    if(position > L.count || position < 0){
        printf("invalid positon");
    } else if (L.count == MAX) {
        printf("puno na");
    } else {
        for(i = L.count; i >= position; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.count++;
        L.elem[position] = data;
    }
    return L;
}

List deletePos(List L, int position){
    int i;
    if (position < 0 || position >= L.count){
        printf("Invalid position");
    } else {
        for (i = position; i < L.count - 1; i++){
            L.elem[i] = L.elem [i - 1];
        }
        L.count--;
        printf("\ndata has been deleted at position %d\n\n", position);
    }
    return L;
}


List locate(List L, StudPtr data){
    int i, j = -1;

    for (i = 0; i < L.count && j == -1; i++){
        if(L.elem[i]->id == data->id){
            j = i;
        }
    }
    return L;
}


List insertSorted (List L, StudPtr data){
    int i, pos = L.count;
    if (L.count == MAX){
        printf("The array is already full.");
    } else {
        for (i = 0; i < L.count && L.elem[i]->id < data->id; i++){
            pos++;
        }
        pos = i;

        for (i = L.count; i > pos; i--){
            L.elem[i] = L.elem[i - 1];
        }

        L.count++;
        L.elem[pos] = data;
    }
    return L;
}

void display(List L){
    int i;
    printf("%-15s %-15s %-10s %-5s %-5s\n", "First Name", "Last Name", "Course", "Yr", "ID");
    printf("--------------------------------------------------------------");

    for(i = 0; i < L.count; i++){
        printf("%-15s %-15s %-10s %-5s %-5s\n", 
            L.elem[i]->name.FName,
            L.elem[i]->name.LName,
            L.elem[i]->course,
            L.elem[i]->age,
            L.elem[i]->id);
    }
}