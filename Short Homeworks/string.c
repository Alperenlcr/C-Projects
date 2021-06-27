#include <stdio.h>
#define MAX 1000

int yeni_islem_sorma()
{
    int secim;
    printf("\nYeni islem yapmak istiyorsaniz 1, istemiyorsaniz baska bir sayi giriniz : ");
    scanf("%d", &secim);
    printf("\n");
    if (secim == 1)
        return 1;
    return 0;
}

void cikma_yazisi()
{
    printf("\nCikis yapiliyor ...\n");
}

void harf_say(char s1[MAX], char s2[MAX])
{
    int sayac1 = 0, sayac2 = 0;
    printf("Baslangic s1 : %s   \t s2 : %s\n", s1, s2);

    while (s1[sayac1] != '\0')
        sayac1 ++;
    while (s2[sayac2] != '\0')
        sayac2 ++;

    printf("s1'in uzunlugu : %d         s2'nin uzunlugu : %d\n", sayac1, sayac2);
    printf("Son hal s1 : %s   \t s2 : %s\n", s1, s2);
}

void s2yi_s1e_kopyala(char s1[MAX], char s2[MAX])
{
    int sayac = 0;
    printf("Baslangic s1 : %s   \t s2 : %s\n", s1, s2);
    while (s2[sayac] != '\0')
    {
        s1[sayac] = s2[sayac];
        sayac ++;
    }
    s1[sayac] = '\0';
    printf("s2 s1 e basariyla kopyalandi.\n");
    printf("Son hal s1 : %s   \t s2 : %s\n", s1, s2);
}

void s1_ile_s2_karsilastir(char s1[MAX], char s2[MAX])
{
    int sayac = 0, ayni=1;
    printf("Baslangic s1 : %s   \t s2 : %s\n", s1, s2);

    while (s1[sayac] != '\0')
    {
        if (s1[sayac] != s2[sayac])
        {
            ayni = 0;
            printf("s1 ve s2 ayni degil.\n");
            break;
        }
        sayac ++;
    }
    if (ayni)
        printf("s1 ve s2 ayni.\n");

    printf("Son hal s1 : %s   \t s2 : %s\n", s1, s2);
}

void s1in_sonuna_s2_ekle(char s1[MAX], char s2[MAX])
{
    int sayac1 = 0, sayac2 = 0;
    printf("Baslangic s1 : %s   \t s2 : %s\n", s1, s2);

    while (s1[sayac1] != '\0')
        sayac1 ++;
    while (s2[sayac2] != '\0')
    {
        s1[sayac1+sayac2] = s2[sayac2];
        sayac2 ++;
    }
    s1[sayac1+sayac2] = '\0';

    printf("s1 in sonuna s2 basariyla eklendi.\n");
    printf("Son hal s1 : %s   \t s2 : %s\n", s1, s2);
}

void s2in_sonuna_s1in_n_adet_harfini_ekle(char s1[MAX], char s2[MAX])
{
    int n, sayac1 = 0, sayac2 = 0;
    printf("Baslangic s1 : %s   \t s2 : %s\n", s1, s2);
    printf("s2'nin sonuna s1'in ilk kac harfi eklensin : ");
    scanf("%d", &n);

    while (s2[sayac2] != '\0')
        sayac2 ++;
    for ( sayac1 = 0; sayac1 < n; sayac1++)
        s2[sayac2+sayac1] = s1[sayac1];
    s2[sayac2+sayac1] = '\0';

    printf("s2'nin sonuna s1'in %d adet harfi basariyla eklendi.\n", n);
    printf("Son hal s1 : %s   \t s2 : %s\n", s1, s2);
}

int main()
{
    char s1[MAX] = "string bir", s2[MAX] = "string iki";
    int secim, ilk;

    menu:
    printf("1-) Dizilerin icerisinde tanimlanan ifadenin kac harften olustugunu bulunuz.\n");
    printf("2-) s2 ile gosterilen dizi icerisindeki ifadeyi s1 ile gosterilen diziye kopyalayiniz.\n");
    printf("3-) s1 ile gosterilen dizi icerisindeki ifadeyi s2 ile gosterilen dizi ile karsilastiriniz.\n");
    printf("4-) s2 ile gosterilen dizi icerisindeki ifadeyi s1 ile gosterilen dizinin pesine ekleyiniz.\n");
    printf("5-) s1 ile gosterilen dizi icerisindeki ifadeyi n harften fazla olmamak uzere s2 ile gosterilen dizinin pesine ekleyiniz.\n");

    ilk = 1;
    do
    {
        if (!ilk)
            printf("Hatali secim denemesi! Tekrar deneyiniz.\n");
        ilk = 0;
        printf("Seciminizi giriniz (1,2,3,4,5) : ");
        scanf("%d", &secim);
    }while (secim>5 || secim<1);
    printf("secim : %d\n", secim);
    switch (secim)
    {
        case 1:
            harf_say(s1, s2);
            break;
        case 2:
            s2yi_s1e_kopyala(s1, s2);
            break;
        case 3:
            s1_ile_s2_karsilastir(s1, s2);
            break;
        case 4:
            s1in_sonuna_s2_ekle(s1, s2);
            break;
        case 5:
            s2in_sonuna_s1in_n_adet_harfini_ekle(s1, s2);
            break;    
    }
    if (yeni_islem_sorma())
        goto menu;
    else
        cikma_yazisi();

    return 0;
}
