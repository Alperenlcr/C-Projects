// durma kosullari
// iterasyon sayisi
// gercek kok (P) var ise |P-xn| < hata
// gercek kok yok ise |x(n+1)-xn| < hata

#include <stdio.h>

float mutlak_deger(float x);
float us_al(float x, int y);
float denklem(float x, float carpanlar[15], int derece);
float denklemin_turevi(float x, float carpanlar2[15], int derece);
void iterasyon_solution(float x0, float iterasyon_sayisi, float carpanlar[15], float carpanlar2[15], int derece);
void gercek_kokle_solution(float x0, float istenilen_hata_miktari, float gercek_deger, float carpanlar[15], float carpanlar2[15], int derece);
void gercek_koksuz_solution(float x0, float istenilen_hata_miktari, float carpanlar[15], float carpanlar2[15], int derece);

int main()
{
    float carpanlar[15] = {0}, carpanlar2[15] = {0};
    int derece, i;
    printf("Girilecek denklemin derecesi : ");
    scanf("%d", &derece);
    for ( i = 0; i <= derece; i++)
    {
        printf("x uzeri %d nin carpanini giriniz : ", i);
        scanf("%f",  &carpanlar[i]);
    }

    printf("\n Turev denklemini de giriniz. \n");
    for ( i = 0; i <= derece-1; i++)
    {
        printf("x uzeri %d nin carpanini giriniz : ", i);
        scanf("%f",  &carpanlar2[i]);
    }
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
            gercek_koksuz_solution(x0, istenilen, carpanlar, carpanlar2, derece);
        else
            gercek_kokle_solution(x0, istenilen, gercek_deger, carpanlar, carpanlar2, derece);
    }
    else
        iterasyon_solution(x0, istenilen, carpanlar, carpanlar2, derece);

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

float denklemin_turevi(float x, float carpanlar2[15], int derece)
{
    int i;
    float res = 0;
    for ( i = 0; i <= derece-1; i++)
        res += carpanlar2[i] * us_al(x, i);
    return res;
}

void iterasyon_solution(float x0, float iterasyon_sayisi, float carpanlar[15], float carpanlar2[15], int derece)
{
    int i;
    float x1_degeri, x1;
    for ( i = 0; i < iterasyon_sayisi; i++)
    {
        x1 = x0 - (denklem(x0, carpanlar, derece) / denklemin_turevi(x0, carpanlar2, derece));
        x1_degeri = denklem(x1, carpanlar, derece);

        printf("\n%d iterasyon sonrasinda bulunan sonuc : f(%f) = %f \n", i+1, x1, x1_degeri);
        x0 = x1;
    }
}

void gercek_kokle_solution(float x0, float istenilen_hata_miktari, float gercek_deger, float carpanlar[15], float carpanlar2[15], int derece)
{
    float x1_degeri, x1, hata_miktari=99;
    while ( hata_miktari > istenilen_hata_miktari )
    {
        x1 = x0 - (denklem(x0, carpanlar, derece) / denklemin_turevi(x0, carpanlar2, derece));
        x1_degeri = denklem(x1, carpanlar, derece);
        hata_miktari =  mutlak_deger( x1 - gercek_deger );
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, x1, x1_degeri);

        x0 = x1;
    }
}

void gercek_koksuz_solution(float x0, float istenilen_hata_miktari, float carpanlar[15], float carpanlar2[15], int derece)
{
    float x1_degeri, x1, hata_miktari=99;
    while ( hata_miktari > istenilen_hata_miktari )
    {
        x1 = x0 - (denklem(x0, carpanlar, derece) / denklemin_turevi(x0, carpanlar2, derece));
        x1_degeri = denklem(x1, carpanlar, derece);
        hata_miktari =  mutlak_deger(x1 - x0);
        printf("\n Hata miktari %f iken bulunan sonuc : f(%f) = %f \n", hata_miktari, x1, x1_degeri);

        x0 = x1;
    }
}

// 1*x*x*x - 7*x*x + 14*x - 6
// 3*x*x - 14*x + 14
// kok : 0.585786 , 3 , 3.4142136

// 5 x^(3)+5 x+10
// 15 x^(2)+5
// kok : -1