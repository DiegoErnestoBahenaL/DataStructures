#include <stdio.h>
#include <stdlib.h>

#define ASCII_LETTERS_START 65

int main (){

    int i;
    char word[32];

    for (i = 0; i < 10; i++){
        word[i] = ASCII_LETTERS_START + i;
    }

    printf("%s\n", word);

    word[4] = 0;

    printf("%s\n", word);

    return 0;
}