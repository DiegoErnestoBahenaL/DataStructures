#include <stdio.h>
#include <stdlib.h>

#define N  5

int main (){

    int array [N][N];

    int i, j;

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            array[i][j] = 0;
        }     
    }
    

    return 0;
}