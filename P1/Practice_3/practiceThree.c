#include <stdio.h>
#include <stdlib.h>

int main(){

    int *pX, *pY;

    static int array[] = {2,5,7,4,5,1};

    pX = &array[0];
    pY = &array[2];

    printf("La multiplicacion de %d X %d es %d\n", *pX, *pY, *pX * *pY);

    printf("El resultado del primer elemento del array + 3 es %d\n", *pX + 3);

    return 0;
}
