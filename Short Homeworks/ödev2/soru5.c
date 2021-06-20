#include <stdio.h>

int main()
{
    int A[5], B[5], C[10];
    int i;

    printf("A dizisinin elemanlarini birer birer giriniz.\n");
    for ( i = 0; i < 5; i++)
        scanf("%d", &A[i]);

    printf("B dizisinin elemanlarini birer birer giriniz.\n");
    for ( i = 0; i < 5; i++)
        scanf("%d", &B[i]);

    for ( i = 0; i < 5; i++)
    {
        C[i] = A[i];
        C[i+5] = B[i];
    }

    printf("C dizisinin elemanlari : ");
    for ( i = 0; i < 10; i++)
    {
        printf("%d ", C[i]);
    }

    return 0;
}