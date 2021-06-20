#include<stdio.h>

void bulBozuklukSayisi(float para, int para_cesitleri[5], int sayac[5])
{
    int index=0;
    para *= 100;
    while (para != 0)
    {
        while (para >= para_cesitleri[index])
        {
            para -= para_cesitleri[index];
            sayac[index] ++;
        }
        index ++;
    }
}

int main()
{
    float para;
    int sayac[5] = {0}, i;
    int para_cesitleri[5] = {100, 50, 25, 10, 5};
    printf("Para miktari : ");
    scanf("%f", &para);
    printf("------------------\n");
    bulBozuklukSayisi(para, para_cesitleri, sayac);

    for ( i = 0; i < 5; i++)
    {
        printf("%d adet %d Krs\n", sayac[i], para_cesitleri[i]);
    }
    return 0;
}