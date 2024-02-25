#include <stdio.h>
#include <stdlib.h>

#define N  5

int main (){

    int corn [N][N];

    int i, j;

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            //%10 pad with spaces on the left at least 10 characters
            printf("%10d\n", corn[i][j]);
        }     
    }

    return 0;
}