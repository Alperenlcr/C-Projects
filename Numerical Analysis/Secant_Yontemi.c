// durma kosullari
// iterasyon sayisi
// gercek kok (P) var ise |P-xn| < hata
// gercek kok yok ise |x(n+1)-xn| < hata

#include <stdio.h>

float mutlak_deger(float x)
{
    if (x < 0)
        x *= -1;
    return x;
}

float denklem(float x)
{
    return x*x*x - 7*x*x + 14*x - 6;
}

float denklemin_turevi(float x0, float x1)
{
    return ( denklem(x0) - denklem(x1) ) / (x0 - x1);
}

void iterasyon_solution(float x0, float x1, float iterasyon_sayisi)
{
    int i;
    float x2_degeri, x2;
    for ( i = 0; i < iterasyon_sayisi; i++)
    {
        x2 = x0 - (denklem(x0) / denklemin_turevi(x0, x1));
        x2_degeri = denklem(x2);

        printf("\n%d iterasyon sonrasinda bulunan sonuc : f(%f) = %f \n", i+1, x2, x2_degeri);
        x0 = x1;
        x1 = x2;
    }
}

void gercek_kokle_solution(float x0, float x1, float istenilen_hata_miktari, float gercek_deger)
{
    float x2_degeri, x2, hata_miktari=99;
    while ( hata_miktari > istenilen_hata_miktari )
    {
        x2 = x0 - (denklem(x0) / denklemin_turevi(x0, x1));
        x2_degeri = denklem(x2);
        hata_miktari =  mutlak_deger(x2 - gercek_deger);
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, x2, x2_degeri);
        x0 = x1;
        x1 = x2;
    }
}

void gercek_koksuz_solution(float x0, float x1, float istenilen_hata_miktari)
{
    float x2_degeri, x2, hata_miktari=99;
    while ( hata_miktari > istenilen_hata_miktari )
    {
        x2 = x0 - (denklem(x0) / denklemin_turevi(x0, x1));
        x2_degeri = denklem(x2);
        hata_miktari =  mutlak_deger(x2 - x1);
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, x2, x2_degeri);
        x0 = x1;
        x1 = x2;
    }
}

int main()
{
    // gerekli girdileri alma
    float istenilen, x0, x1, gercek_deger;
    printf("\nIstenilen hata miktari sinirini veya iterasyon sayisini giriniz (iterasyon sayisi 2 den buyuk olmalidir) : ");
    scanf("%f", &istenilen);
    printf("\n x1 ve x0 degerlerini bir bosluk birakarak giriniz : ");
    scanf("%f %f", &x1, &x0); // -5, -4  ,  14, 15

    // durma kosuluna gore fonksiyona gonderme
    if (istenilen < 3.0)
    {
        printf("\nGercek kokun x degerini giriniz (bilinmiyorsa 999 giriniz.): ");
        scanf("%f", &gercek_deger); // 0.585786438 , 3.414213
        if (gercek_deger == 999)
            gercek_koksuz_solution(x0, x1, istenilen);
        else
            gercek_kokle_solution(x0, x1, istenilen, gercek_deger);
    }
    else
        iterasyon_solution(x0, x1, istenilen);

    return 0;
}
