#include <stdio.h>
#define MAX 20

void matris_yazdir(float A[MAX][MAX], float B[MAX], int boyut);
void matris_olustur(float A[MAX][MAX], float B[MAX], int *boyut);
void matris_duzenleme(float A[MAX][MAX], float B[MAX], int boyut);
float mutlak_deger(float x);
float denklem(float sonuclar[MAX], float carpanlar[20], float b, int index, int boyut);
void cozum(float A[MAX][MAX], float B[MAX], int boyut);

int main()
{
    float A[MAX][MAX], B[MAX];
    int boyut;
    matris_olustur(A, B, &boyut);
    printf("\n[A:B] Matrisi (Girilen sekilde)\n------------------\n");
    matris_yazdir(A, B, boyut);
    matris_duzenleme(A, B, boyut);
    printf("\n[A:B] Matrisi (Duzenlendikten sonra)\n------------------\n");
    matris_yazdir(A, B, boyut);
    cozum(A, B, boyut);
    printf("\n");
    return 0;
}

void matris_yazdir(float A[MAX][MAX], float B[MAX], int boyut)
{
    int i, j;
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
    printf("\nOrnek:\n-x + 4y - 3z = -8\n3x + y - 2z = 9\nx - y + 4z = 1\ndenklemleri icin ornek girdi : ");
    printf("\n\nA:\n-1  4 -3\n 3  1 -2\n 1 -1  4\n\nB:\n-8  9  1\n------------------------------------");

    printf("\nA Matrisinin boyutunu giriniz : ");
    scanf("%d", boyut);
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

void matris_duzenleme(float A[MAX][MAX], float B[MAX], int boyut)
{
    int i, j, k, index=0;
    float temp, max;
    for ( j = 0; j < boyut; j++)
    {
        max=-9999;
        for ( i = j; i < boyut; i++)
        {
            if (max < A[i][j])
            {
                max = A[i][j];
                index = i;
            }
        }
        if (j != index)
        {
            for ( k = 0; k < boyut; k++)
            {
                temp = A[j][k];
                A[j][k] = A[index][k];
                A[index][k] = temp;
            }
            temp = B[j];
            B[j] = B[index];
            B[index] = temp;
        }
    }
}

float mutlak_deger(float x)
{
    if (x < 0)
        x *= -1;
    return x;
}

float denklem(float sonuclar[MAX], float carpanlar[20], float b, int index, int boyut)
{
    float bol = carpanlar[index];
    int i;
    float res;
    for ( i = 0; i < boyut; i++)
    {
        if (i != index)
        {
            b -= carpanlar[i]*sonuclar[i];
        }
    }
    res = b / bol;
    return res;
}

void cozum(float A[MAX][MAX], float B[MAX], int boyut)
{
    float sonuc[MAX], sonuc_eski[MAX], hata=999, istenilen_hata;
    int i, j, ite=0;
    printf("\n");
    for ( i = 0; i < boyut; i++)
    {
        printf("x%d icin baslama degerini giriniz : ", (i+1));
        scanf("%f", &sonuc[i]);
    }
    printf("\nHata miktarini giriniz : ");
    scanf("%f", &istenilen_hata);

    printf("\nIterasyon");
    for ( i = 0; i < boyut; i++)
    {
        if (i != 0)
            printf("\t");
        printf("\tx%d", i+1);
    }
    printf("\n");
    do
    {
        ite ++;
        for ( i = 0; i < boyut; i++)
        {
            sonuc_eski[i] = sonuc[i];
            sonuc[i] = denklem(sonuc, A[i], B[i], i, boyut);
        }
        printf("%d\t\t", ite);
        for ( i = 0; i < boyut; i++)
            printf("%f\t", sonuc[i]);
        printf("\n");
        for ( i = 0; i < boyut; i++)
        {
            if (hata > mutlak_deger(sonuc[i]-sonuc_eski[i]))
                hata = mutlak_deger(sonuc[i]-sonuc_eski[i]);
        }
    }while(hata > istenilen_hata);
}
