#include <stdio.h>
#include <stdlib.h>

int main (){

    int length = 10, numbers[length], i;
   
    int *pointer = numbers;


    for (pointer; pointer < (numbers + length); pointer ++){
        scanf ("%d", pointer);
    }

    for (i = 0; i < length; i++){
        printf ("%d\n", i, numbers[i]);
    }

    return 0;
}