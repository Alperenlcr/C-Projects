#include <stdio.h>
#define MAX 100

void cozum(float x[MAX], float y[MAX], float istenilen_x);
int elemanlar_ayni_mi(float dizi[MAX]);
float islem(float x[MAX], float delta_f, float istenilen_x, int count, float h);
float us_al(float x, int y);
int fact_al(int x);

int main()
{
    float x[MAX], y[MAX], temp, istenilen_x;
    int i=0;
    printf("\nBilinen x ve y degerlerini giriniz. Deger girmeyi bitimek icin x'e 99 giriniz.");
    printf("\nNOT : x ler arasi artim miktari (h) sabit olmalidir.");
    printf("\nx : ");
    scanf("%f", &x[i]);
    while (x[i] != 99)
    {
        printf("f(%f) : ", x[i]);
        scanf("%f", &y[i]);
        i ++;
        printf("\nx : ");
        scanf("%f", &x[i]);
    }
    printf("Girdiginiz degerler ile uydurulacak fonksiyonda bakilacak x degerini giriniz : ");
    scanf("%f", &istenilen_x);
    cozum(x, y, istenilen_x);
    return 0;
}

void cozum(float x[MAX], float y[MAX], float istenilen_x)
{
    float carpanlar[MAX], delta_f[MAX], h, result=y[0], delta_f_0[MAX];
    int i=0, count=1;
    h = x[1] - x[0];
    while (x[i] != 99)
    {
        delta_f[i] = y[i];
        i ++;
    }
    delta_f[i] = 99;
    delta_f_0[0] = delta_f[0];
    while (!elemanlar_ayni_mi(delta_f))
    {
        i=0;
        while (delta_f[i+1] != 99)
        {
            delta_f[i] = delta_f[i+1] - delta_f[i];
            i ++;
        }
        delta_f[i] = 99;
        i=0;
        while (delta_f[i] != 99)
        {
            printf("%f ", delta_f[i]);
            i ++;
        }
        printf("\n");
        delta_f_0[count] = delta_f[0];
        result += islem(x, delta_f_0[count], istenilen_x, count, h);
        count ++;
    }
    printf("F(%f) : %f\n", istenilen_x, result);
}

int elemanlar_ayni_mi(float dizi[MAX])
{
    int i=0;
    while (dizi[i] != 99 && dizi[0] == dizi[i])
        i ++;
    if (dizi[i] == 99)
        return 1;
    else
        return 0;
}

float islem(float x[MAX], float delta_f, float istenilen_x, int count, float h)
{
    float ust=1, alt;
    alt = fact_al(count)*us_al(h, count);
    ust *= delta_f;
    count --;
    for (; count >= 0; count--)
        ust *= istenilen_x-x[count];
    return ust/alt;
}

float us_al(float x, int y)
{
    if (y == 0)
        return 1;
    else
        return us_al(x, y-1)*x;
}

int fact_al(int x)
{
    if (x==1)
        return 1;
    return x*fact_al(x-1);
}
