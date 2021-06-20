#include <stdio.h>

int main()
{
    char sifre_matrisi[6][5] = {
        {'A', 'J', 'K', 'P', 'Ü'},
        {'B', 'İ', 'L', 'R', 'V'},
        {'C', 'I', 'M', 'S', 'Y'},
        {'Ç', 'H', 'N', 'Ş', 'Z'},
        {'D', 'G', 'O', 'T', '.'},
        {'E', 'F', 'Ö', 'U', '?'}
    };
    int i, satirlar[10], sutunlar[10], temp;
    printf("Sifreli mesajin sayilarini birer birer giriniz.(10 adet)\n");
    for ( i = 0; i < 10; i++)
    {
        scanf("%d", &temp);
        satirlar[i] = (temp / 10) - 1;
        sutunlar[i] = (temp % 10) - 1;
    }

    for ( i = 0; i < 10; i++)
    {
        printf("%c", sifre_matrisi[satirlar[i]][sutunlar[i]]);
    }

    return 0;
}
/*
34
32
43
11
25
54
11
33
11
33

*/