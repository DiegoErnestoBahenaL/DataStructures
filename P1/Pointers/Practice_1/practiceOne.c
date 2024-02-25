#include <stdio.h>
#include <stdlib.h>

int main (){

    int number = 10;

    printf("number is: %d\n", number);

    printf ("the address of number is: %p\n ", (void *) &number);

    return 0;
}
