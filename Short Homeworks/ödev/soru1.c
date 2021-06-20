#include <stdio.h>

int main()
{
    printf("20 adet sayi giriniz.\n");
    int i, sayi, adet=0, toplam=0;
    for ( i = 1; i <= 20; i++)
    {
        scanf("%d", &sayi);
        if (sayi % 2 == 0)
        {
            adet ++;
            toplam += sayi;
        }
    }
    printf("Girilen sayilardan %d adet cift sayinin aritmetik ortalamasi = %.2f", adet, ((toplam*1.0)/(adet*1.0)));

    return 0;
}
/*
5
2
1
4
7
6
3
8
6
10
5
2
1
4
7
6
3
8
6
10

*/
