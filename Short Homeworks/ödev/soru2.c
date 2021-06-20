#include <stdio.h>

int main()
{
    int i, j, yukseklik;
    printf("Yuksekligi giriniz :");
    scanf("%d", &yukseklik);
    for ( i = 1; i <= yukseklik; i++)
    {
        for ( j = 0; j < i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
    for ( i = yukseklik-1; i > 0; i--)
    {
        for ( j = 0; j < i; j++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
    
    return 0;
}
