#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    
    int i;
    char wordOne[32], wordTwo[32];

    scanf("%s", wordOne);
    scanf("%s", wordTwo);

    printf("%s vs %s\n", wordOne, wordTwo);

    printf("Iguales? %s\n", (strcmp(wordOne, wordTwo) == 0 ? "Si" : "No"));

    printf("Longitudes: %d y %d\n", strlen(wordOne), strlen(wordTwo));

    printf ("Concatenación: %s\n", strcat(wordOne, wordTwo));

    return 0;
}