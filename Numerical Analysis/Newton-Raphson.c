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

float denklemin_turevi(float x)
{
    return 3*x*x - 14*x + 14;
}

void iterasyon_solution(float x0, float iterasyon_sayisi)
{
    int i;
    float x1_degeri, x1;
    for ( i = 0; i < iterasyon_sayisi; i++)
    {
        x1 = x0 - (denklem(x0) / denklemin_turevi(x0));
        x1_degeri = denklem(x1);

        printf("\n%d iterasyon sonrasinda bulunan sonuc : f(%f) = %f \n", i+1, x1, x1_degeri);
        x0 = x1;
    }
}

void gercek_kokle_solution(float x0, float istenilen_hata_miktari, float gercek_deger)
{
    float x1_degeri, x1, hata_miktari=99;
    while ( hata_miktari > istenilen_hata_miktari )
    {
        x1 = x0 - (denklem(x0) / denklemin_turevi(x0));
        x1_degeri = denklem(x1);
        hata_miktari =  mutlak_deger( x1 - gercek_deger );
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, x1, x1_degeri);

        x0 = x1;
    }
}

void gercek_koksuz_solution(float x0, float istenilen_hata_miktari)
{
    float x1_degeri, x1, hata_miktari=99;
    while ( hata_miktari > istenilen_hata_miktari )
    {
        x1 = x0 - (denklem(x0) / denklemin_turevi(x0));
        x1_degeri = denklem(x1);
        hata_miktari =  mutlak_deger(x1 - x0);
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, x1, x1_degeri);

        x0 = x1;
    }
}
int main()
{
    // gerekli girdileri alma
    float istenilen, x0, gercek_deger;
    printf("\nIstenilen hata miktari sinirini veya iterasyon sayisini giriniz (iterasyon sayisi 2 den buyuk olmalidir) : ");
    scanf("%f", &istenilen);
    printf("\nBakilacak ilk x degerini giriniz : ");
    scanf("%f", &x0); // 0

    // durma kosuluna gore fonksiyona gonderme
    if (istenilen < 3.0)
    {
        printf("\nGercek kokun x degerini giriniz (bilinmiyorsa 999 giriniz.): ");
        scanf("%f", &gercek_deger); // 0.585786438
        if (gercek_deger == 999)
            gercek_koksuz_solution(x0, istenilen);
        else
            gercek_kokle_solution(x0, istenilen, gercek_deger);
    }
    else
        iterasyon_solution(x0, istenilen);

    return 0;
}