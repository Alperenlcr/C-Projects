#include <stdio.h>

float us_al(float x, int y);
float denklem(float x, float carpanlar[15], int derece);
float ileri_fark(float x, float h, float carpanlar[15], int derece);
float geri_fark(float x, float h, float carpanlar[15], int derece);
float merkezi_fark(float x, float h, float carpanlar[15], int derece);

int main()
{
    float carpanlar[15] = {0}, h, x;
    int derece, i;
    printf("Turevi alinacak denklemin derecesi : ");
    scanf("%d", &derece);
    for ( i = 0; i <= derece; i++)
    {
        printf("x uzeri %d nin carpanini giriniz : ", i);
        scanf("%f",  &carpanlar[i]);
    }
    printf("Fark (h) : ");
    scanf("%f", &h);
    printf("Turevine bakilacak nokta (x) : ");
    scanf("%f", &x);
    printf("\n----------------------\n\n");
    printf("Ileri farklar ile sayisal turev sonucu f'(%f) = %f\n", x, ileri_fark(x, h, carpanlar, derece));
    printf("Geri farklar ile sayisal turev sonucu f'(%f) = %f\n", x, geri_fark(x, h, carpanlar, derece));
    printf("Merkezi farklar ile sayisal turev sonucu f'(%f) = %f\n", x, merkezi_fark(x, h, carpanlar, derece));

    return 0;
}

float us_al(float x, int y)
{
    if (y == 0)
        return 1;
    else
        return us_al(x, y-1)*x;
}

float denklem(float x, float carpanlar[15], int derece)
{
    int i;
    float res = 0;
    for ( i = 0; i <= derece; i++)
        res += carpanlar[i] * us_al(x, i);
    return res;
}

float ileri_fark(float x, float h, float carpanlar[15], int derece)
{
    float res;
    res = denklem(x+h, carpanlar, derece) - denklem(x, carpanlar, derece);
    res /= h;
    return res;
}

float geri_fark(float x, float h, float carpanlar[15], int derece)
{
    float res;
    res = denklem(x, carpanlar, derece) - denklem(x-h, carpanlar, derece);
    res /= h;
    return res;
}

float merkezi_fark(float x, float h, float carpanlar[15], int derece)
{
    float res;
    res = denklem(x+h, carpanlar, derece) - denklem(x-h, carpanlar, derece);
    res /= 2*h;
    return res;
}
