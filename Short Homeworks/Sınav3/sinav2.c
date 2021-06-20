#include <stdio.h>

void solution(float midterm, float final)
{
    float ave;
    char letter;
    ave = midterm * 0.40 + final * 0.6;
    if (ave>=90)
        letter = 'A';
    else if (ave>=80)
        letter = 'B';
    else if (ave>=70)
        letter = 'C';
    else if (ave>=60)
        letter = 'D';
    else
        letter = 'F';   
    printf("Your letter grade is : %c\n", letter);
}

int main()
{
    float midterm, final;
    int positive = 1;
    do
    {
        printf("Enter your midterm grade : ");
        scanf("%f", &midterm);
        printf("Enter your final grade : ");
        scanf("%f", &final);
        if (midterm < 0 || final < 0)
            positive = 0;
        else
            solution(midterm, final);
        printf("\n");
    } while (positive);
    printf("You entered negative value. Bye");
    return 0;
}
