#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 20

void matris_yazdir(float matris[MAX][MAX], int boyut);
void matris_olustur(float matris[MAX][MAX], int *boyut);
void cozum(float matris[MAX][MAX], float ters_matris[MAX][MAX], int boyut);

int main()
{
    srand(time(NULL));
    float matris[MAX][MAX], ters_matris[MAX][MAX];
    int boyut;
    matris_olustur(matris, &boyut);
    printf("\nMatris\n------------------\n");
    matris_yazdir(matris, boyut);
    cozum(matris, ters_matris, boyut);
    printf("\nMatrisin tersi\n------------------\n");
    matris_yazdir(ters_matris, boyut);
    printf("\n");
    return 0;
}

void matris_yazdir(float matris[MAX][MAX], int boyut)
{
    int i, j;
    for ( i = 0; i < boyut; i++)
    {
        for ( j = 0; j < boyut; j++)
        {
            printf("%.2f ", matris[i][j]);
        }
        printf("\n");   
    }
}

void matris_olustur(float matris[MAX][MAX], int *boyut)
{
    int i, j;
    do
    {
        printf("\nMatrisin boyutunu giriniz : ");
        scanf("%d", boyut);
        
    } while (*boyut<1);
    

    for ( i = 0; i < *boyut; i++)
    {
        for ( j = 0; j < *boyut; j++)
        {
            printf("\n%d. sutun %d. satirdaki elemani giriniz : ", (i+1), (j+1));
            scanf("%f", &matris[i][j]);
            // matris[i][j] = rand() % 20;
        }
    }
}

void cozum(float matris[MAX][MAX], float ters_matris[MAX][MAX], int boyut)
{
    int i, j, k;
    float temp, temp2;

    for ( i = 0; i < boyut; i++)
    {
        for ( j = 0; j < boyut; j++)
        {
            if (i == j)
                ters_matris[i][j] = 1;
            else
                ters_matris[i][j] = 0;
        }
    }
    for ( i = 0; i < boyut; i++)
    {
        temp = matris[i][i];
        for ( j = 0; j < boyut; j++)
        {
            matris[i][j] /= temp;
            ters_matris[i][j] /= temp;
        }
        for ( k = 0; k < boyut; k++)
        {
            if (k != i)
            {
                temp2 = matris[k][i];
                for ( j = 0; j < boyut; j++)
                {
                    matris[k][j] -= matris[i][j]*temp2;
                    ters_matris[k][j] -= ters_matris[i][j]*temp2;
                }   
            }
        }
    }
}

/*
5.00 2.00 -4.00 
1.00 4.00 2.00 
2.00 3.00 6.00

0.17 -0.23 0.19 
-0.02 0.36 -0.13 
-0.05 -0.10 0.17
*/