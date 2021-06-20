#include <stdio.h>

void letter_grade(float, float);

int main()
{
    float Midterm, Final;
    printf("\nEnter your Midterm grade : ");
    scanf("%f", &Midterm);
    printf("Enter your Final grade : ");
    scanf("%f", &Final);
    while (Midterm >= 0 && Final >= 0)
    {
        letter_grade(Midterm, Final);
        printf("\nEnter your Midterm grade : ");
        scanf("%f", &Midterm);
        printf("Enter your Final grade : ");
        scanf("%f", &Final);
    }
    printf("You entered negative value. Bye\n");
    return 0;
}

void letter_grade(float Midterm, float Final)
{
    float Average;
    char grade;
    Average = Midterm * 0.40 + Final * 0.6;
    if (Average>=90)
        grade = 'A';
    else if (Average>=80)
        grade = 'B';
    else if (Average>=70)
        grade = 'C';
    else if (Average>=60)
        grade = 'D';
    else
        grade = 'F';   
    printf("Your Letter Grade is : %c\n", grade);
}
