#include <stdio.h>

float ikinci_en_kucuk(float dizi[], int size);

int main()
{
    float dizi[6] = {3.4, 12.5, 1, 5.6, 7.8, 9.7};

    printf("Dizinin ikinci en kucuk elemani : %.2f\n", ikinci_en_kucuk(dizi, 6));

    return 0;
}

float ikinci_en_kucuk(float dizi[], int size)
{
    int i;
    float min=dizi[0], ikinci=dizi[0];
    for ( i = 1; i < size; i++)
    {
        if (dizi[i] < min)
        {
            ikinci = min;
            min = dizi[i];
        }
        else if (dizi[i] < ikinci)
        {
            ikinci = dizi[i];
        }
    }
    
    return ikinci;
}