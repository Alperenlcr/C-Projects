/*
#include<stdio.h>
#include<string.h>
int main()
{
    int array[100000], toplam =0; 
    int i, number_of_digits; 
    scanf("%d", &number_of_digits);
    for (i = 0; i < number_of_digits; i++) { 
  
        scanf("%d", &array[i]);
        getchar();
    } 
  
    for (i = 0; i < number_of_digits; i++)  
        printf("%d ", array[i]); 
    
    printf("\n");


    for(i = 0; i < number_of_digits; i++)
        toplam += array[i];
    
    for ( i = 2; i < number_of_digits; i++)
    {
        if (toplam % i == 0)
        {
            printf("%d",i);
            break;
        }
    }
}
*/
/*
ilk_kale = int(input())
ilk_fetih = list(map(int, input().split()))
liste_uzunlugu = max(*ilk_fetih)
sayi_dogrusu = [0] * liste_uzunlugu

for i in ilk_fetih:
    sayi_dogrusu[i-1] = 1

name = 0
broke = True

while broke:
    broke = False
    for i in reversed(range(liste_uzunlugu)):
        if sayi_dogrusu[i] == 1:
            for j in reversed(range(i)):
                if sayi_dogrusu[j] == 1 and sayi_dogrusu[i - j - 1] != 1:
                    sayi_dogrusu[i - j - 1] = 1
                    name += 1
                    broke = True

if name % 2 == 1:
    print("burak")
else:
    print("bilge")
    */
/*  
#include<stdio.h>

int largest(long arr[], int n) 
{ 
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
} 

int main()
{
    int baslangic, i, j;
    scanf("%d",&baslangic);
    long ilk_fetih[500], liste_uzunlugu;

    for (i = 0; i < baslangic; i++)
    {
        scanf("%ld", &ilk_fetih[i]);
        getchar();
    }

    liste_uzunlugu = largest(ilk_fetih,baslangic);
    printf("%ld",liste_uzunlugu);
    int sayi_dogrusu[liste_uzunlugu];


    int name = 0, broke = 1;
    while (broke)
    {
        broke = 0;
        for ( i = liste_uzunlugu-1; i >= 0; i--)
        {
            if (sayi_dogrusu[i] == 1)
            {
                for ( i = i-1; i >= 0; j--)
                {
                    if (sayi_dogrusu[j] == 1 && sayi_dogrusu[i-j-1] != 1)
                    {
                        sayi_dogrusu[i-j- 1] = 1;
                        name += 1;
                        broke = 1;
                    }
                    
                }
            }
            
        }
    }
    if (name % 2 == 1)
    {
        printf("Burak");
    }
    else
    {
        printf("Bilge");
    }
}
*/
/*
#include<stdio.h>
#include <stdlib.h>

int main()
{
    int boy, dongu, i;
    char tip;
    scanf("%d", &boy);
    getchar();
    int tek = 1;
    float mesafe, *edges_harcanacak;
    edges_harcanacak = (float*) malloc(boy * sizeof(float));
    for (i = 0; i < 2*(boy-1); i++)
    {
        if(tek)
        {
            scanf("%c", &tip);
            tek = 0;
        }
        else
        {
            scanf("%f", &mesafe);
            if(tip == 'b')
                edges_harcanacak[(i-1)/2] = mesafe * (0.058);
            else if (tip == 'o')
                edges_harcanacak[(i-1)/2] = mesafe * (0.072);
            else if (tip == 'h')
                edges_harcanacak[(i-1)/2] = mesafe * (0.086);
            tek = 1;
        }
        getchar();
    }
    scanf("%d", &dongu);
    int temp, first, last, counter, j;
    float tank;
    for (i = 0; i < dongu; i++)
    {
        scanf("%d %d", &first, &last);
        if (first > last)
        {
            temp = first;
            first = last;
            last = temp;
        }
        counter = 0;
        tank = 50.00;
        for (j = first-1; j < last-1; j++)
        {
            if (edges_harcanacak[j] <= tank)
                tank = tank - edges_harcanacak[j];
            else if (edges_harcanacak[j] > 50.00)
            {
                counter = -1;
                break;
            }
            else
            {
                counter ++;
                tank = 50.00 - edges_harcanacak[j];        
            }
        }
        printf("%d\n", counter);
    }
    free(edges_harcanacak);
    return 0;
}
*/
