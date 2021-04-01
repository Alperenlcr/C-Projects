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

// Don't forget to define equation
float denklem(float x)
{
    return x*x*x - 7*x*x + 14*x - 6;
}

void iterasyon_solution(float x0, float x1, float iterasyon_sayisi)
{
    int i;
    float alt_deger, orta_deger, ust_deger, c;
    for ( i = 0; i < iterasyon_sayisi; i++)
    {
        c = (x0+x1) / 2;
        alt_deger = denklem(x0);
        orta_deger = denklem(c);
        ust_deger = denklem(x1);

        if (orta_deger*ust_deger < 0)
            x0 = c;
        else
            x1 = c;

        printf("\n%d iterasyon sonrasinda bulunan sonuc : f(%f) = %f \n", i+1, c, orta_deger);
    }
}

void gercek_kokle_solution(float x0, float x1, float istenilen_hata_miktari, float gercek_deger)
{
    int i=0;
    float alt_deger, orta_deger, ust_deger, c, hata_miktari=istenilen_hata_miktari+2;
    while (hata_miktari > istenilen_hata_miktari)
    {
        c = (x0+x1) / 2;
        alt_deger = denklem(x0);
        orta_deger = denklem(c);
        ust_deger = denklem(x1);

        if (orta_deger*ust_deger < 0)
            x0 = c;
        else
            x1 = c;

        hata_miktari = mutlak_deger( c - gercek_deger );
        i++;
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, c, orta_deger);
    }
}

void gercek_koksuz_solution(float x0, float x1, float istenilen_hata_miktari)
{
    int i=0;
    float alt_deger, orta_deger, ust_deger, c, hata_miktari=istenilen_hata_miktari+2;
    while (hata_miktari > istenilen_hata_miktari)
    {
        c = (x0+x1) / 2;
        alt_deger = denklem(x0);
        orta_deger = denklem(c);
        ust_deger = denklem(x1);

        if (orta_deger*ust_deger < 0)
        {
            x0 = c;
            hata_miktari = mutlak_deger( x1 - c );
        }
        else
        {
            x1 = c;
            hata_miktari = mutlak_deger( c - x0 );
        }

        i++;
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, c, orta_deger);
    }
}

int main()
{
    // gerekli girdileri alma
    float istenilen, x0, x1, gercek_deger;
    printf("\nIstenilen hata miktari sinirini veya iterasyon sayisini giriniz (iterasyon sayisi 2 den buyuk olmalidir) : ");
    scanf("%f", &istenilen);
    printf("\nBakilacak x degerleri aralagi (alt sinir ve ust siniri aralarinda bosluk olacak sekilde giriniz.) : ");
    scanf("%f %f", &x0, &x1);

    // durma kosuluna gore fonksiyona gonderme
    if (istenilen < 3.0)
    {
        printf("\nGercek kokun x degerini giriniz (bilinmiyorsa 999 giriniz.): ");
        scanf("%f", &gercek_deger); // 0.585786
        if (gercek_deger == 999)
            gercek_koksuz_solution(x0, x1, istenilen);
        else
            gercek_kokle_solution(x0, x1, istenilen, gercek_deger);
    }
    else
        iterasyon_solution(x0, x1, istenilen);

    return 0;
}