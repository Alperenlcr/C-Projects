#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int matris[10][10];
    int i, j, satir, sutun, max=0;
    printf("\nMATRIS :\n");
    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            matris[i][j] = rand() % 50 + 1;
            printf("%3d ", matris[i][j]);
        }
        printf("\n");
    }

    for ( i = 0; i < 10; i++)
    {
        for ( j = 0; j < 10; j++)
        {
            if (max < matris[i][j])
            {
                satir = i;
                sutun = j;
                max = matris[i][j];
            }
        }
    }
    printf("En buyuk elemanin degeri : %d\n", max);
    printf("Satiri : %d     Sutunu : %d\n", (satir+1), (sutun+1));
    return 0;
}