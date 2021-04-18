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
    return x*x - 6*x + 5;
}

void iterasyon_solution(float x0, float delta_x, float iterasyon_sayisi)
{
    int i;
    float alt_deger, ust_deger;
    for ( i = 0; i < iterasyon_sayisi; i++)
    {
        do
        {
            alt_deger = denklem(x0);
            ust_deger = denklem(x0 + delta_x);
            x0 += delta_x;
        } while (alt_deger * ust_deger > 0);
        x0 -= delta_x;
        delta_x /= 2;
        printf("\n%d iterasyon sonrasinda bulunan sonuc : f(%f) = %f \n", i+1, x0, alt_deger);
    }
}

void gercek_kokle_solution(float x0, float delta_x, float istenilen_hata_miktari, float gercek_deger)
{
    int i=0;
    float alt_deger, ust_deger, hata_miktari=istenilen_hata_miktari+1;
    while (hata_miktari > istenilen_hata_miktari)
    {
        i++;
        do
        {
            alt_deger = denklem(x0);
            ust_deger = denklem(x0 + delta_x);
            x0 += delta_x;
        } while (alt_deger * ust_deger > 0);
        x0 -= delta_x;
        delta_x /= 2;
        hata_miktari = mutlak_deger(gercek_deger - x0);
        printf("\n Hata miktari %f iken bulunan %d sonuc : f(%f) = %f \n", hata_miktari, i, x0, alt_deger);
    }
}

void gercek_koksuz_solution(float x0, float delta_x, float istenilen_hata_miktari)
{
    int i=0;
    float alt_deger, ust_deger;
    while (delta_x > istenilen_hata_miktari)
    {
        i++;
        do
        {
            alt_deger = denklem(x0);
            ust_deger = denklem(x0 + delta_x);
            x0 += delta_x;
        } while (alt_deger * ust_deger > 0);
        x0 -= delta_x;
        delta_x /= 2;
        printf("\n Hata miktari (delta x) %f iken bulunan %d sonuc : f(%f) = %f \n", delta_x, i, x0, alt_deger);
    }
}

int main()
{
    // gerekli girdileri alma
    float istenilen, x0, delta_x, gercek_deger;
    printf("\nIstenilen hata miktari sinirini veya iterasyon sayisini giriniz (iterasyon sayisi 2 den buyuk olmalidir) : ");
    scanf("%f", &istenilen);
    printf("\nIlk bakilacak x degeri ve ilk bakilacak aralik genisligini bir bosluk ile giriniz. : ");
    scanf("%f %f", &x0, &delta_x);  // 1.5 0.75

    // durma kosuluna gore fonksiyona gonderme
    if (istenilen < 3.0)
    {
        printf("\nGercek kokun x degerini giriniz (bilinmiyorsa 999 giriniz.): ");
        scanf("%f", &gercek_deger); // 5
        if (gercek_deger == 999)
            gercek_koksuz_solution(x0, delta_x, istenilen);
        else
            gercek_kokle_solution(x0, delta_x, istenilen, gercek_deger);
    }
    else
        iterasyon_solution(x0, delta_x, istenilen);

    return 0;
}