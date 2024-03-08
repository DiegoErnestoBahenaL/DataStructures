#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (){

    int array[10] = {26, 30, 1 ,76, 50, 65, 13, 23, 45, 100};

    int length = sizeof(array)/sizeof(array[0]);


    printf("Unsorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n\n");

    int aux = 0;


    for (int i = length - 1; i >= 0; i--){
        
        int largestIndex = i;

        for (int j = 0; j < i; j++){

            if (array[j] > array[largestIndex]){

                largestIndex = j;
            }

        }

        if (largestIndex != i){
            
            aux = array[largestIndex];

            array[largestIndex] = array[i];

            array[i] = aux;
        }
    }

    
     printf("Sorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    

    return 0;
}