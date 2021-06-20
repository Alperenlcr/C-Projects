#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void tarihUret(int, char);

int main()
{
    srand(time(NULL));
    int adet;
    char mevsim;
    printf("\nKac tane tarih uretilsin : ");
    scanf("%d", &adet);
    printf("\nilkbahar ise 'i' sonbahar ise 's' giriniz : ");
    scanf(" %c", &mevsim);

    tarihUret(adet, mevsim);
    return 0;
}

void tarihUret(int adet, char mevsim)
{
    printf("\n-----------------------\n");
    int i = 0, yil, ay, gun, ay_ekle;
    if (mevsim == 'i')
        ay = 3;
    else
        ay = 9;

    for ( i = 0; i < adet; i++)
    {
        yil = 2021 + rand() % 51;
        ay_ekle = rand() % 3;
        gun = rand() % 30 + 1;
        printf("%2d / %2d / %4d\n", gun, (ay+ay_ekle), yil);
    }
    
}
