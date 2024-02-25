#include <stdio.h>
#include <stdlib.h>

int main (){


    int length = 10, numbers[10], i;
    int *pointer;

    numbers[0] = 0;

    for (i = 1; i < length; i++){
        numbers[i] = numbers [i - 1] + 1;
    }

    for (pointer = numbers; pointer < (numbers + 10); pointer++){
        printf("%d\n", *pointer);
    }

    return 0;    
}