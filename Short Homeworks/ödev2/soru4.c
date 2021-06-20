#include <stdio.h>

void histogram_cizdir(int);

int main()
{
    int i, dizi[10];

    printf("Teker teker 10 adet sayi giriniz.\n");
    
    for ( i = 0; i < 10; i++)
        scanf("%d", &dizi[i]);
    
    printf("\nSayilar ve histogramlari\n\n");
    
    for ( i = 0; i < 10; i++)
        histogram_cizdir(dizi[i]);

    return 0;
}

void histogram_cizdir(int sayi)
{
    int i;
    
    printf("\n%d\t", sayi);
    for ( i = 0; i < sayi; i++)
        printf("*");
    
    printf("\n");
}

/*
15
16
17
20
1
6
29
4
9
10

*/