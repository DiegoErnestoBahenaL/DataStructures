#include <stdio.h>
#include <stdlib.h>

#define N  5

int main (){

    int corn [N][N];

    int i, j, cantidad = 1;

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            corn[i][j] = cantidad;
            cantidad *= 2;
        }     
    }

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
           printf("%10d\n", corn[i][j]);
        }     
    }

    return 0;
}