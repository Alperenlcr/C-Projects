#include <stdio.h>
#include <stdlib.h>

// 15
// Yarin saat oniki'de bulusalim.
// Npgxc hppi dcxzx'st qjajhpaxb.

void cozum(int X);

void main(int argc, char *argv[])
{
    if(argc == 2)
    {
        //argv[0] programin adi, atoi = string haldeki sayiyi int tipine donusturmek icin
        cozum(atoi(argv[1]));
    }
    else
        printf("Kullanim sekli : sifrele sayi\n");
}

void cozum(int X)
{
    // tersine gidilecegi icin -1 ile carpiyoruz
    X *= -1;
    // sifrele.c deki koda ek olarak periyodik tur kisimlarindaki if kosulunu degistiriyoruz.

    char ilk[200],Son[200];
	int i=0,deger;

	printf("Sifreli yaziyi giriniz : ");
    scanf("%[^\n]", ilk);

	while(ilk[i]!='\0')
	{
		deger = ilk[i] + X;
		if(ilk[i]>='a'&&ilk[i]<='z') 				//kücük harf mi ?
		{
			if(deger<'a')		//periyodik tur atacak mı ?
			{
				Son[i] = 'z'-('a'-deger)%26 + 1;
			}
			else
			{
				Son[i] = deger;
			}
		}
		else if(ilk[i]>='A'&&ilk[i]<='Z')			//büyük harf mi ?
		{
			if(deger<'A')		//periyodik tur atacak mı ?
			{
				Son[i] = 'Z'-('A'-deger)%26 + 1;
			}
			else
			{
				Son[i] = deger;
			}
		}
		else										//harf değil
		{
			Son[i] = ilk[i];
		}
		i++;
	}
	printf("Sifresi cozulmus hali : %s\n",Son);
}