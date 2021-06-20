#include <stdio.h>
#define MAX 100

int main()
{
    int matris[MAX][MAX]={0};
    int i, j, n;
    int N, M, secim;
    int x, y, max_x=0, max_y=0, deger;

    do
    {
    	// menu yazdirma
	    printf("Menu :\n");
        printf("(1) Seyrek matristen sikistirilmis matrise\n");
        printf("(2) Sikistirilmis matristen seyrek matrise\n");
        printf("(3) Cikis\n");

        printf("Secim : ");
        scanf("%d", &secim);

        if (secim == 1)
        {
            printf("Matris boyutunu arada bir bosluk birakarak ( (satir sutun) seklinde ) giriniz : ");
            scanf("%d %d", &N, &M);

            // matrisi alma
            printf("\nMatrisin elemanlarini giriniz.\n");
            for ( i = 0; i < N; i++)
            {
                for ( j = 0; j < M; j++)
                {
                    printf("[%d] [%d] : ", i, j);
                    scanf("%d", &matris[i][j]);
                }
                printf("\n");
            }

            // Sikistirilmis matris tablosu yazdirma
            printf("Sikistirilmis matris\n");
            printf("Satir\tSutun\tDeger\n------\t------\t------\n");
            for ( i = 0; i < N; i++)
            {
                for ( j = 0; j < M; j++)
                {
                    if (matris[i][j] != 0)
                    {
                        printf("%d\t%d\t%d\n", i, j, matris[i][j]);
                        matris[i][j] = 0;
                        // tekrar kullanma ihtimaline karsi sifirlama yapiyoruz

                        // istenilirse burada (MAX)x3 boyutunda bir matrisde degerler saklanabilir.
                        // saklama_matrisi[counter][0] = i
                        // saklama_matrisi[counter][1] = j
                        // saklama_matrisi[counter][2] = matris[i][j]    yapilabilir.
                        // counter burada 1 arttirilir dongulerin disinda 0 olarak tanimlanir.
                        // Odev aciklamasinda acikca istenmemis o yuzden yorum satiri icinde nolur nolmaz ekledim.
                    }
                }
            }
        }

        else if (secim == 2)
        {
            printf("Matriste kac tane sifirdan farkli eleman var : ");
            scanf("%d", &n);

            // eleman degerlerini alma
            for ( i = 0; i < n; i++)
            {
                printf("%d. Eleman icin satir, sutun, deger bilgilerini aralarinda birer bosluk birakarak giriniz : ", i+1);
                scanf("%d %d %d", &x, &y, &deger);

                matris[x][y] = deger;
                
                // bunlarin amaci yazdirma kisminda bir sinir olusturmak
                if (x > max_x)
                {
                    max_x = x;
                }
                if (y > max_y)
                {
                    max_y = y;
                }
            }
            
            // seyrek matris yazdirma
            printf("\nSeyrek matris \n");
            for ( i = 0; i <= max_x; i++)
            {
                for ( j = 0; j <= max_y; j++)
                {
                    printf("%d  ", matris[i][j]);
                    // tekrar kullanilmasi durumu (do-while dongusu icinde) icin matrisi sifirlamamiz gerekiyor.
                    matris[i][j] = 0;
                }
                printf("\n");
            }
            max_x = 0;
            max_y = 0;
        }
        printf("\n\n");

    } while (secim != 3);
    

    return 0;
}
