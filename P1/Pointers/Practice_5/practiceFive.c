#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

int main (){

    char alpha[] = "abcdefghijklmnopqrstuvxyz";
    
    int alphaLength = strlen(alpha);


    for (i = 0; i < alphaLength; i++)
    {
        char character = alpha[i];

        printf("\n%c = %d\t", character, character);
    }
    

    return 0;
}