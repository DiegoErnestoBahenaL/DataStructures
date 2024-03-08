#include <stdio.h>
#include <stdlib.h>

int main (){


    int array[10] = {26, 30, 1 ,76, 50, 65, 13, 23, 45, 100};

    int length = sizeof(array)/sizeof(array[0]);


    printf("Unsorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n\n");


    for (int i = 1; i < length; i++){

        int next = array[i];

        int j;

        for (j = i - 1; j >= 0 && array[j] > next; j--){
            array[j + 1] = array [j];
        }

        array[j + 1] = next;

    }

    printf("Sorted array:\n");

    for (int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}