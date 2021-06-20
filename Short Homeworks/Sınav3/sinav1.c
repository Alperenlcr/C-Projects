#include <stdio.h>

void print_grade(int, int);

int main()
{
    int mid, fin;
    while (1)
    {
        printf("\nEnter your Midterm grade : ");
        scanf("%d", &mid);
        printf("Enter your Final grade : ");
        scanf("%d", &fin);
        if (mid < 0 || fin < 0)
            break;
        print_grade(fin, mid);
    }
    printf("You entered negative value. Bye\n");
    return 0;
}

void print_grade( int f, int m)
{
    float a = m * 0.4 + f * 0.6;
    if (a < 60)
        printf("Your Letter Grade is : F\n");
    else if (a < 70)
        printf("Your Letter Grade is : D\n");
    else if (a < 80)
        printf("Your Letter Grade is : C\n");
    else if (a < 90)
        printf("Your Letter Grade is : B\n");
    else
        printf("Your Letter Grade is : A\n");
}
