#include <stdio.h>

int main()
{
    int SayilarDizisi[12] = {30, 25, 22, 17, 98, 47, 3, 55, 126, 10, 49, 11}; // diziyi tanimlama
    int secim, sayi, i, j, min, temp; // bazi kullanacagimiz degiskenleri tanimlama

    do
    {
    	// menu yazdirma
	    printf("\n\nMenu :\n");
        printf("(1) Dizideki elemanlardan istenilenilen sayiya tam bolunenleri gosterme\n");
        printf("(2) Kucukten buyuge siralanmis dizideki istelen indexteki elemani gosterme\n");
        printf("(3) Cikis\n");

        printf("Secim : ");
        scanf("%d", &secim);

        if (secim == 1)
        {
            printf("Sayi giriniz : ");
            scanf("%d", &sayi);

            printf("Dizide bulunup da %d sayisina tam bolunen elemanlar : ", sayi);
            for ( i = 0; i < 12; i++)
            {
                if (SayilarDizisi[i] % sayi == 0)
                {
                    printf("%d  ", SayilarDizisi[i]);
                }
            }
        }

        else if (secim == 2)
        {
            printf("[1, 12] araliginda sayi giriniz : ");
            scanf("%d", &sayi);
            sayi --; // dizide index 0 dan basladigi icin

            for (i = 0; i < 11; i++)
            {
                // Siralanmamis dizideki minimum elemani bulma
                min = i;
                for (j = i+1; j < 12; j++)
                {
                    if (SayilarDizisi[j] < SayilarDizisi[min])
                    {
                        min = j;
                    }
                }

                // bulunan minumum deger ile bastan kaldigimiz yerdeki degeri degistirme
                temp = SayilarDizisi[min];
                SayilarDizisi[min] = SayilarDizisi[i];
                SayilarDizisi[i] = temp;
            }

            printf("Kucukten buyuge siralanmis dizideki %d. eleman : %d\n", sayi+1, SayilarDizisi[sayi]);
        }

        if( secim < 1 || secim > 3 )
        {
            printf("\nYanlis tercih yaptiniz menuye tekrar yonlendiriliyorsunuz.\n");
        }

    } while (secim != 3);

    return 0;
}