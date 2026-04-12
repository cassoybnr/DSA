#include <stdio.h>
#include <string.h>
#include "header.h"

void insertEnd(List *L, VHeap *vh, char song[], char artist[]) {
    int newNode = allocSpace(vh);

    if(newNode != -1){
        strcpy(vh->nodes[newNode].song_name, song);
        strcpy(vh->nodes[newNode].artist, artist);
        vh->nodes[newNode].next = -1;

        if(*L == -1){
            *L = newNode;
        } else {
            int last = *L;
            while (vh->nodes[last].next != -1){
            last = vh->nodes[last].next;
        }
        vh->nodes[last].next = newNode;
        }
        printf("Song added successfully.\n");
    } else {
        printf("Playlist is full. Cannot add more songs.\n");
    }
}

void deleteSong(List *L, VHeap *vh, char song[]) {
    if(*L == -1){
        printf("Playlist is empty.\n");
        return;
    }

    int current = *L;
    int previous = -1;

    while (current != -1 && strcmp(vh->nodes[current].song_name, song) != 0){
        previous = current;
        current = vh->nodes[current].next;
    }

    if(current != -1){
        if (previous == -1){
            *L = vh->nodes[current].next;
        }else {
            vh->nodes[previous].next = vh->nodes[current].next;
        }
        freeSpace(vh, current);
        printf("Song deleted successfully.\n");
    } else {
        printf("Song '%s' not found.\n", song);
    }

}