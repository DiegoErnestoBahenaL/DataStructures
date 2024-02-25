#include <stdio.h>
#include <stdlib.h>

int main (){

    char x[] = "este es un ejemplo de arreglos sin puntero\n";
    char *y = "este es un ejemplo de arreglos con puntero\n";

    printf("%s", x);
    printf("%s", y);

    return 0;
}
