#include <stdio.h>
#include <stdlib.h>

int main (){

    int number = 10;

    int *pNumber = &number;

    printf("Number is: %d\n", number);

    printf ("The address *pNumber points to is: %p\n", (void *) &number);

    printf ("The value *pNumber points is: %d\n", *pNumber);

    return 0;
}
