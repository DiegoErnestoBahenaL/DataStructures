#include <stdio.h>
#include <stdlib.h>


void swap(int *arrayAddress, int index);

int main (){

    int aux = 0;

    int array[10] = {26, 30, 1 ,5, 50, 65, 3, 23, 45, 10};

    int length = sizeof(array)/sizeof(array[0]);

    short sorted = 0;


    // for (int i = 0; i < length - 1; i++){

    //     for (int j = 0;  j < length -1 ; j++ ){

    //         if (array[j] < array[j + 1]){

    //             aux = array[j];
    //             array[j] = array [j + 1];
    //             array[j + 1] = aux;

    //         }
    //     }
    // } 

    short swaps;

    while (sorted != 1){

        swaps = 0;

        for (int j = 0;  j < length -1 ; j++ ){

            if (array[j] > array[j + 1]){

                swaps = 1;

                swap(array, j);
            }

        }

        if (swaps == 0){
            sorted = 1;
        }
    } 


    return 0;
}

void swap(int *arrayAddress, int index){

    arrayAddress += index;

    int  aux = *(arrayAddress);

    *arrayAddress = *(arrayAddress + 1);

    *(arrayAddress + 1) = aux;
}