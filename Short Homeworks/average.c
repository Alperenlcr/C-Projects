#include<stdio.h>

int main()
{
    int lower_limit, upper_limit, first, change;
    int l_odd, l_even, u_odd, u_even, temp;
    char choice;
    do
    {
        printf("Please enter lower bound : ");
        scanf("%d", &lower_limit);
        printf("Please enter upper bound : ");
        scanf("%d", &upper_limit);
        change = 0;
        
        if (lower_limit>upper_limit)
        {
            temp = upper_limit;
            upper_limit = lower_limit;
            lower_limit = temp;
            change = 1;
        }
        
        if (lower_limit % 2 == 0)
        {
            l_odd = lower_limit+1;
            l_even = lower_limit;
        }
        else
        {
            l_even = lower_limit+1;
            l_odd = lower_limit;
        }
        
        if (upper_limit % 2 == 0)
        {
            u_odd = upper_limit-1;
            u_even = upper_limit;
        }
        else
        {
            u_even = upper_limit-1;
            u_odd = upper_limit;
        }

        if (change)
        {
            temp = upper_limit;
            upper_limit = lower_limit;
            lower_limit = temp;
        }
        
        printf("Average of even numbers between %d-%d is %.2f\n", lower_limit, upper_limit, ( (l_even+u_even) / 2.0 ));
        printf("Average of odd numbers between %d-%d is %.2f\n", lower_limit, upper_limit, ( (l_odd+u_odd) / 2.0 ));
        first = 0;
        do
        {
            if (first)
            {
                printf("You have entered wrong character! Please enter Y/y for yes, N/n for no : ");
            }
            else
            {
                printf("Do you want to continue? (Y/y for yes, N/n for no) : ");
                first = 1;
            }
            scanf(" %c", &choice);

        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
        
        printf("\n-------------------------------------------------------------\n\n");
    } while (choice == 'Y' || choice == 'y');

    return 0;
}