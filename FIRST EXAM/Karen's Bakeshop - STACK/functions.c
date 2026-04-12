#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"header.h"

/*
 * @brief Counts how many layers of a given radius exist in the stack
 * @param C pointer to the cake stack
 * @param radius integer value representing the layer radius
 * @return number of layers in the stack that match the given radius
 */

 int countRadius(CAKE *C, int radius){
    CAKE tempStack;
    initStack(&tempStack);
    int count = 0;

    while(!isEmpty(*C)){
        CakeLayer current = top(*C);
        if(current.radius == radius){
            count++;
        }
        push(&tempStack, current);
        pop(C);
    }

    while(!isEmpty(tempStack)){
        push(C, top(tempStack));
        pop(&tempStack);
    }

    return count;
 }

/*
 * @brief Pushes a new cake layer into the CAKE stack following the rules
 *        uses the countRadius function to get the count of layers of the
 *        same radius in order to be within the stack constraints
 * @param C pointer to the cake stack
 * @param Layer is a CakeLayer structure containing radius and flavor of the new cake layer
 * @return void
 */
void pushLayer(CAKE *C, CakeLayer Layer) {
    //write your code here...
    //push(C, Layer);
    if(isFull(*C)){
        printf("\nError:Cake is Fully Stacked!\n");
        return;
    }

    if(countRadius(C, Layer.radius) >= 3){
        printf("Error: already 3 layers of this radius %d.\n", Layer.radius);
        return;
    }
    if(!isEmpty(*C)){
        CakeLayer topLayer = top(*C);
        if(Layer.radius > topLayer.radius){
            printf("Error: Radius %d is not smaller than top radius %d.\n", Layer.radius, topLayer.radius);
            return;
        }
    }

    push(C, Layer);
    printf("Pushed %s (radius %d).\n", Layer.flavor, Layer.radius);
    
}