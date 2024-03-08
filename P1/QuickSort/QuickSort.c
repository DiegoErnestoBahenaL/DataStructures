#include <stdio.h>
#include <stdlib.h>



void quickSort(int array[], int startIndex, int endIndex);

int partition(int array[], int startIndex, int endIndex);

void swap (int array[], int firstIndex, int secondIndex);

int main (){


    int array[10] = {26, 30, 100 ,76, 75, 45, 23, 96, 13, 61};

    int length = sizeof(array)/sizeof(array[0]);


    printf("Unsorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n\n");

    
    quickSort (array, 0, length - 1);


    printf("Sorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n");


    return 0;
}

void quickSort(int array[], int startIndex, int endIndex){

    if (startIndex < endIndex){
       
       int partitionIndex = partition (array, startIndex, endIndex);

        quickSort (array, startIndex, partitionIndex - 1);
        quickSort (array, partitionIndex + 1, endIndex);
    }  

}


int partition (int array[], int startIndex, int endIndex){

    int partitionIndex = startIndex;

    int pivot = array[endIndex];


    for (int i = startIndex; i < endIndex; i++){
        
        if (array[i] <= pivot){
            
            swap(array, i, partitionIndex);

            partitionIndex ++;
        }

    }

    swap(array, partitionIndex, endIndex);


    return partitionIndex;
}

void swap (int array[], int firstIndex, int secondIndex){
   
    int aux = array[firstIndex];

    array[firstIndex] = array[secondIndex];

    array[secondIndex] = aux;

}
