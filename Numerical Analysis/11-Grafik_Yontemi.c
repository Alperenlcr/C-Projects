// durma kosullari
// iterasyon sayisi
// gercek kok (P) var ise |P-xn| < hata
// gercek kok yok ise |x(n+1)-xn| < hata

#include <stdio.h>

float mutlak_deger(float x);
float us_al(float x, int y);
float denklem(float x, float carpanlar[15], int derece);
void iterasyon_solution(float x0, float x1, float iterasyon_sayisi, float carpanlar[15], int derece);
void gercek_kokle_solution(float x0, float x1, float istenilen_hata_miktari, float gercek_deger, float carpanlar[15], int derece);
void gercek_koksuz_solution(float x0, float x1, float istenilen_hata_miktari, float carpanlar[15], int derece);

int main()
{
    float carpanlar[15] = {0};
    int derece, i;
    printf("Girilecek denklemin derecesi : ");
    scanf("%d", &derece);
    for ( i = 0; i <= derece; i++)
    {
        printf("x uzeri %d nin carpanini giriniz : ", i);
        scanf("%f",  &carpanlar[i]);
    }

    // gerekli girdileri alma
    float istenilen, x0, delta_x, gercek_deger;
    printf("\nIstenilen hata miktari sinirini veya iterasyon sayisini giriniz (iterasyon sayisi 2 den buyuk olmalidir) : ");
    scanf("%f", &istenilen);
    printf("\nIlk bakilacak x degeri ve ilk bakilacak aralik genisligini bir bosluk ile giriniz. : ");
    scanf("%f %f", &x0, &delta_x);

    // durma kosuluna gore fonksiyona gonderme
    if (istenilen < 3.0)
    {
        printf("\nGercek kokun x degerini giriniz (bilinmiyorsa 999 giriniz.): ");
        scanf("%f", &gercek_deger);
        if (gercek_deger == 999)
            gercek_koksuz_solution(x0, delta_x, istenilen, carpanlar, derece);
        else
            gercek_kokle_solution(x0, delta_x, istenilen, gercek_deger, carpanlar, derece);
    }
    else
        iterasyon_solution(x0, delta_x, istenilen, carpanlar, derece);

    return 0;
}

float mutlak_deger(float x)
{
    if (x < 0)
        x *= -1;
    return x;
}

float us_al(float x, int y)
{
    if (y == 0)
        return 1;
    else
        return us_al(x, y-1)*x;
}

float denklem(float x, float carpanlar[15], int derece)
{
    int i;
    float res = 0;
    for ( i = 0; i <= derece; i++)
        res += carpanlar[i] * us_al(x, i);
    return res;
}

void iterasyon_solution(float x0, float delta_x, float iterasyon_sayisi, float carpanlar[15], int derece)
{
    int i;
    float alt_deger, ust_deger;
    for ( i = 0; i < iterasyon_sayisi; i++)
    {
        do
        {
            alt_deger = denklem(x0, carpanlar, derece);
            ust_deger = denklem((x0+delta_x), carpanlar, derece);
            x0 += delta_x;
        } while (alt_deger * ust_deger > 0);
        x0 -= delta_x;
        delta_x /= 2.0;
        printf("\n%d iterasyon sonrasinda bulunan sonuc : f(%f) = %f \n", i+1, x0, alt_deger);
    }
}

void gercek_kokle_solution(float x0, float delta_x, float istenilen_hata_miktari, float gercek_deger, float carpanlar[15], int derece)
{
    int i=0;
    float alt_deger, ust_deger, hata_miktari=istenilen_hata_miktari+1;
    while (hata_miktari > istenilen_hata_miktari)
    {
        i++;
        do
        {
            alt_deger = denklem(x0, carpanlar, derece);
            ust_deger = denklem((x0+delta_x), carpanlar, derece);
            x0 += delta_x;
        } while (alt_deger * ust_deger > 0);
        x0 -= delta_x;
        delta_x /= 2;
        hata_miktari = mutlak_deger(gercek_deger - x0);
        printf("\n%d ) Hata miktari %f iken bulunan : f(%f) = %f \n", i, hata_miktari, x0, alt_deger);
    }
}

void gercek_koksuz_solution(float x0, float delta_x, float istenilen_hata_miktari, float carpanlar[15], int derece)
{
    int i=0;
    float alt_deger, ust_deger;
    while (delta_x > istenilen_hata_miktari)
    {
        i++;
        do
        {
            alt_deger = denklem(x0, carpanlar, derece);
            ust_deger = denklem((x0+delta_x), carpanlar, derece);
            x0 += delta_x;
        } while (alt_deger * ust_deger > 0);
        x0 -= delta_x;
        delta_x /= 2;
        printf("\n %d ) Hata miktari (delta x) %f iken bulunan : f(%f) = %f \n", i, delta_x, x0, alt_deger);
    }
}

// 1*x*x*x - 7*x*x + 14*x - 6
// kok : 0.585786

// 5 x^(3)+5 x+10
// kok : -1