#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void swap(int *arrayAddress, int index);

int main (){

    int aux = 0;

    int array[10] = {26, 30, 1 ,5, 50, 65, 3, 23, 45, 10};

    int length = sizeof(array)/sizeof(array[0]);

   

    printf("Unsorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n\n");

    for (int i = length - 1; i >= 0; i--){

        bool sorted = true;

        for (int j = 0;  j < i ; j++ ){

            if (array[j] > array[j + 1]){

                sorted = false;

                swap(array, j);
            }

        }

        if (sorted){
            break;
        }
    } 

    printf("Sorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}

void swap(int *arrayAddress, int index){

    arrayAddress += index;

    int  aux = *(arrayAddress);

    *arrayAddress = *(arrayAddress + 1);

    *(arrayAddress + 1) = aux;
}