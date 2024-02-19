#include <stdio.h>
#include <stdlib.h>

int main (){

    int number, *pNumber;

    number = 10;

    pNumber = &number;

    printf("number is: %d\n", number);

    printf ("the address pointerNumber points to is: %p\n", (void *) &number);

    printf ("the value *pNumber points is: %d\n", *pNumber);

    return 0;
}
