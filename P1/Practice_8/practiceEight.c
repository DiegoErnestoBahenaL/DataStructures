#include <stdio.h>
#include <stdlib.h>

int i, numberOfValues, *pValue, *pNull = NULL;

int main (){
    
    printf("Ingresa cuantos valores a introducir:\n");

    scanf("%d", &numberOfValues );

    pValue =  (void *) malloc(numberOfValues * (sizeof(int)));

    for (i = 0; i < numberOfValues; i++){
        printf("Ingresa el valor numerico:\n");

        scanf("%d", pValue + i);
    }

    for ( i = 0; i < numberOfValues; i++)
    {
        printf("El elemento numero %d es %d\n", i + 1,* (pValue + i));
    }

    free(pValue);
    

    return 0;
}