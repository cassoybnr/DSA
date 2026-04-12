#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"header.h"


/*
 * @brief Inserts a new gym class into the schedule for a given day
 * @param G pointer to the gym schedule
 * @param newGC the new gymClass to be inserted
 * @param Day string representing the day of the week
 *
 */

void insertClass(gymSchedule* G, gymClass newGC, String Day) {
    //Write your code here...
    
    int dayIdx = getDay(Day);
    if(dayIdx == -1) {
        printf("Error: Invalid day.\n");
        return;
    }

    if(G->dayOf[dayIdx].count >= MAX){
        printf("Error: Max classes reached for the day.\n");
        return;
    }

    if(strlen(newGC.instructor) == 0 || strcmp(newGC.instructor, "0") == 0) {
        printf("Error: Instructor cannot be empty.\n");
        return;
    }

    if(newGC.duration > 1){
        printf("Error: Duration exceeds 1 hour.\n");
        return;
    }

    if(newGC.minSize < MIN){
        printf("Error: Minimum size not enough.\n");
        return;
    }

    nodePtr current = G->dayOf[dayIdx].N;
    while(current!= NULL){
        if(strcmp(current->C.name, newGC.name) == 0){
            printf("Error: Duplicate class name on %s.\n", Day);
            return;
        }
        current = current->link;
    }
    
    nodePtr newNode = (nodePtr)malloc(sizeof(nodeType));
    if(newNode == NULL) {
        printf("Error: Memory allocation failed.\n ");
        return;
    }
    
    printf("Class inserted successfully on %s.\n\n", Day);
    newNode->C = newGC;
    newNode->link = NULL;

    if(G->dayOf[dayIdx].N == NULL){
        G->dayOf[dayIdx].N = newNode;
    } else {
        current = G->dayOf[dayIdx].N;
        while(current->link != NULL){
            current = current->link;
        }
        current->link = newNode;
    }
    G->dayOf[dayIdx].count++;
    G->count++;

}