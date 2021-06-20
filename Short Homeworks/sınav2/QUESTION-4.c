#include <stdio.h>

int main()
{
    int num1, num2, i, j, temp, res;
    scanf("%d", &num1);
    scanf("%d", &num2);
    res = num1*num2;
    printf("            %d\n", num1);
    printf("x           %d\n", num2);
    printf("---------------\n");
    for ( i = 2; i >= 0; i--)
    {
        printf("         ");
        for ( j = 0; j < i; j++)
            printf(" ");
        
        temp = num2%10;
        num2 /= 10;
        printf("%d\n", num1*temp);        
    }
    printf("---------------\n");
    printf("         %d\n", res);
    return 0;
}
