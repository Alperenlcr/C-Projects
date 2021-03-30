#include <stdio.h>
#include <math.h>

// SOLUTION
/*
// prime --> p
// not prime --> np
// N : 20
// 3   4   5   6   7   8   9   10 ||| 11  12  13  14  15  16  17  18  19  20
// p
// 20-3=17
// 17 is p

// 20 - 2 = 18

// 3   4   5   6   7   8   9 |||  10  11  12  13  14  15  16  17  18
// p
// 18-3=15
// 15 is np
// 3   4   5   6   7   8   9 |||  10  11  12  13  14  15  16  17  18
//     np
// 3   4   5   6   7   8   9 |||  10  11  12  13  14  15  16  17  18
//         p
//       18-5=13
// 13 is p

// 18 - 2 = 16

// ...  ... ... ... ...
*/

int is_prime(unsigned int number)
{
    // Corner case
    if (number <= 1)
        return 0;

    long i, edge;

    // 98 printf("number: %d\n",number);
    // We know number is odd
    edge = (number+1)/2;
    // edge = sqrt(number);
    i = 2;

    while (i < edge)
    {
        if (number % i == 0)
            return 0;
        i++;
    }
 
    return 1;
}

int solution(unsigned int biggest)
{
    long lower_bound = 3;
    long upper_bound = biggest/2;

    while (  !(  is_prime(lower_bound) && is_prime(biggest-lower_bound)  ) && lower_bound <= upper_bound)
    {
        lower_bound+=2;
    }

    if (lower_bound-1 == upper_bound)
        return 0;
    if (biggest > 6)
        solution(biggest-2);
    // printf("%ld + %ld = %d\n", lower_bound, biggest-lower_bound, biggest);
    return 1;
}

unsigned int get_input()
{
    unsigned int value;
    printf("\nEnter Value (Number) : ");
    scanf("%d", &value);
    if (value<=4)
    {
        printf("\nValue has to be greater than 4. Try again.\n");
        get_input();
    }
    else if (value % 2 == 1)
        value++;

    return value;
}

void main ()
{
    unsigned int N;
    // gets greater than 4 and even number
    N = get_input();

    if (solution(N))
        printf("\nTheory is not wrong for input : %d \n",N);
    else
        printf("\nTheory is wrong !!!\n");
}
