#include <stdio.h>

int main()
{
    int notlar[10], i;
    int toplam=0;
    float ortalama;
    for ( i = 0; i < 10; i++)
    {
        printf("%d. Ogrencinin notu : ", (i+1));
        scanf("%d", &notlar[i]);
        toplam += notlar[i];
    }
    ortalama = (toplam*1.0) / 10.0;
    printf("\nOrtalama uzeri notlar: ");
    for ( i = 0; i < 10; i++)
    {
        if (notlar[i] > ortalama)
        {
            printf("%d ", notlar[i]);
        }
    }
    
    return 0;
}
