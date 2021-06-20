#include <stdio.h>
void harfe_cevir(int vize, int final)
{
    float not = vize*0.4 + final*0.6;
    if (not >= 80)
        printf("Ogrencinin harf notu : A");
    
    else if (not >= 70)
        printf("Ogrencinin harf notu : B");
    
    else if (not >= 60)
        printf("Ogrencinin harf notu : C");

    else if (not >= 50)
        printf("Ogrencinin harf notu : D");

    else
        printf("Ogrencinin harf notu : E");
}
int main()
{
    int vize, final;
    printf("Ogrencinin vize notunu giriniz : ");
    scanf("%d", &vize);

    printf("Ogrencinin final notunu giriniz : ");
    scanf("%d", &final);

    harfe_cevir(vize, final);
    return 0;
}
