#include <stdio.h>
#define MAX 20

void matris_yazdir(float A[MAX][MAX], float B[MAX], int boyut);
void matris_olustur(float A[MAX][MAX], float B[MAX], int *boyut);
void cozum(float A[MAX][MAX], float B[MAX], int boyut);

int main()
{
    float A[MAX][MAX], B[MAX];
    int boyut;
    matris_olustur(A, B, &boyut);
    matris_yazdir(A, B, boyut);
    cozum(A, B, boyut);
    printf("\n");
    return 0;
}

void matris_yazdir(float A[MAX][MAX], float B[MAX], int boyut)
{
    int i, j;
    printf("\n[A:B] matrisi\n------------------\n");
    for ( i = 0; i < boyut; i++)
    {
        for ( j = 0; j < boyut; j++)
        {
            printf("%f ", A[i][j]);
        }
        printf("%f\n", B[i]);
    }
}

void matris_olustur(float A[MAX][MAX], float B[MAX], int *boyut)
{
    int i, j;
    printf("\n[A][X] = [B] denklem sisteminde X'i bulmak icin once A matrisini sonra B matrisini giriniz.");
    printf("\nOrnek:\n-x + 4y – 3z = -8\n3x + y - 2z = 9\nx - y + 4z = 1\ndenklemleri icin ornek girdi : ");
    printf("\n\nA:\n-1  4 -3\n 3  1 -2\n 1 -1  4\n\nB:\n-8  9  1\n------------------------------------");

    *boyut = 0;
    while (*boyut<1)
    {
        printf("\nA Matrisinin boyutunu giriniz : ");
        scanf("%d", boyut);
    }
    printf("\n");
    for ( i = 0; i < *boyut; i++)
    {
        for ( j = 0; j < *boyut; j++)
        {
            printf("A matrisinin %d. sutun %d. satirdaki elemani giriniz : ", (i+1), (j+1));
            scanf("%f", &A[i][j]);
        }
    }
    printf("\n");
    for ( i = 0; i < *boyut; i++)
    {
        printf("B matrisinin %d. elemanini giriniz : ", i+1);
        scanf("%f", &B[i]);
    }
}

void cozum(float A[MAX][MAX], float B[MAX], int boyut)
{
    float x[MAX];
    int i, j, k;
    float c, sum=0.0;

    // matrisi guncelleme
    for(i=0; i<boyut; i++)
    {
        for(j=0; j<boyut; j++)
        {
            if(j>i)
            {
                c = A[j][i] / A[i][i];
                for(k=0; k<boyut; k++)
                {
                    A[j][k] -= c * A[i][k];
                }
                B[j] -= c * B[i];
            }
        }
    }

    // B yi olusturma
    x[boyut-1] = B[boyut-1] / A[boyut-1][boyut-1];
    for(i=boyut-2; i>=0; i--)
    {
        sum=0;
        for(j=i+1; j<boyut; j++)
            sum += A[i][j] * x[j];

        x[i] = (B[i]-sum) / A[i][i];
    }
    printf("\nCOZUM : \n");
    for(i=0; i<boyut; i++)
        printf("\nx%d = %f\t", i+1, x[i]);
}
