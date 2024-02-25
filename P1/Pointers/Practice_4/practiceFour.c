#include <stdio.h>
#include <stdlib.h>

#define arraySize 5

int grades [arraySize] = {98,5,7,23,5};
int i = 0, *pGrades;

int main(){

    pGrades = &grades[0];

    for (i = 0; i < arraySize; i++){

        printf("La calificacion %d es %d\n", i + 1, *(pGrades + i));
    }

    return 0;
}