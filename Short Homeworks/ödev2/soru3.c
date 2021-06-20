#include <stdio.h>
#define ons 28.3495231;

float grons_cevir(float, char);

int main()
{
    printf("%.7f\n", grons_cevir(3, 'o'));

    return 0;
}

float grons_cevir(float miktar, char tur)
{
    if(tur == 'o')
        return miktar*ons;
    return miktar/ons;
}