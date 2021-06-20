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
	char ilk[200],son[200];
	int i=0, deger;

	printf("Sifrelemek istediginiz yaziyi giriniz : ");
    scanf("%[^\n]",ilk);

	while(ilk[i]!='\0')
	{
		deger = ilk[i] + X;
		if(ilk[i]>='a'&&ilk[i]<='z') 				//kücük harf mi ?
		{
			if(deger>'z')		//periyodik tur atacak mı ?
			{
				son[i] = (deger-'z')%26 + 'a' - 1;
			}
			else
			{
				son[i] = deger;
			}
		}
		else if(ilk[i]>='A'&&ilk[i]<='Z')			//büyük harf mi ?
		{
			if(deger>'Z')		//periyodik tur atacak mı ?
			{
				son[i] = (deger-'Z')%26 + 'A' - 1;
			}
			else
			{
				son[i] = deger;
			}
		}
		else										//harf değil
		{
			son[i] = ilk[i];
		}
		i++;
	}
	printf("Sifrelenmis hali : %s\n", son);
}