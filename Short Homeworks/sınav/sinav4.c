#include <stdio.h>

void f(int *pgun, int *psaat, int *pdakika, int *psaniye);

int main()
{
    int gun, saat, dakika, saniye;

    printf("Gün sayını giriniz : ");
    scanf("%d", &gun);
    
    f(&gun, &saat, &dakika, &saniye);

    printf("%d gün %d saat %d dakika %d saniyedir.\n", gun, saat, dakika, saniye);

    return 0;
}

void f(int *pgun, int *psaat, int *pdakika, int *psaniye)
{
    *psaat = (24 * (*pgun));
    *pdakika = (24 * (*pgun)) * 60;
    *psaniye = (24 * (*pgun)) * 60 * 60;
}
