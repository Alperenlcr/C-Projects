#include <stdio.h>

int main()
{
    int max=-99999, min=99999;
    int sayi;
    do
    {
        printf("\nBir sayı giriniz (çıkmak için -1): ");
        scanf("%d", &sayi);
        if (max<sayi)
        {
            max = sayi;
        }
        else if (min>sayi)
        {
            min = sayi;
        }

    } while (sayi != -1);
    printf("Girilen sayıların en küçüğü %d en büyüğü %d dir.\n", min, max);

    return 0;
}
