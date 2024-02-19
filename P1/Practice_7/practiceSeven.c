#include <stdio.h>
#include <stdlib.h>

int main (){
    
    int * pNumber;
    int milles = 22, distance = 158;

    pNumber = &milles;

    printf ("La direccion almacenada en pNumber es %p\n", (void *) pNumber);
    printf ("El valor al que pNumber apunta es %d\n", *pNumber);

    pNumber = &distance;

    printf ("La direccion almacenada en pNumber es %p\n", (void *) pNumber);
    printf ("El valor al que pNumber apunta es %d\n", *pNumber);

    return 0;
}