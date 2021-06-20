#include<stdio.h>
#define MAX 1000

int main()
{
    int array[MAX], size, i;
    int left_index, middle_index, rigth_index;
    int found = 0;
    //**********************************************************
    //  INPUT ALMA
    printf("\nGirilecek dizinin eleman sayisini giriniz : ");
    scanf("%d", &size);
    for ( i = 0; i < size; i++)
    {
        printf("\n%d. Eleman : ", i+1);
        scanf("%d", &array[i]);
    }
    //**********************************************************
//-----------------------------------------------------------------
    //**********************************************************
    //      COZUM

    if (array[size-1] == array[0] + size-1)
    {
        printf("\nEksik deger yoktur.\n");
    }
    else
    {
        left_index = 0;
        rigth_index = size-1;
        middle_index = (left_index+rigth_index)/2;
        printf("%d ",middle_index);
        while ( !found )
        {
            
            if (array[middle_index] - array[left_index] != middle_index-left_index)
            {
                rigth_index = middle_index;
                middle_index = (left_index+rigth_index)/2;
            }
            else if (array[rigth_index] - array[middle_index] != rigth_index-middle_index)
            {
                left_index = middle_index;
                middle_index = (left_index+rigth_index)/2;
            }


            if (rigth_index-middle_index == 1 && array[rigth_index]-array[middle_index] != 1)
            {
                printf("Eksik deger = %d", array[middle_index]+1);
                found = 1;
            }
            else if (middle_index-left_index == 1 && array[middle_index]-array[left_index] != 1)
            {
                printf("Eksik deger = %d", array[left_index]+1);
                found = 1;
            }
        }
    }
    //**********************************************************
    return 0;
}