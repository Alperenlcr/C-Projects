#include<stdio.h>
#include<stdlib.h>
#include<string.h>


float* stack ;
int top = 0;
int dimension = 2;
//Pushing number to the stack
void push(float number);
//Deleting the last value and print to the screen if it is demanded
float pop();
//Print all stack
void print_Stack();
void postfix_arithmetic(char tokens[5]);
int isNumber(char value);




int main()
{
    stack = (float*)malloc(sizeof(float)*dimension);
    char tokens[5];    
    char copy[5];
    int control = 1;
    float result = 0;
    
    printf("\nTo finish, enter the word 'end'.\n\n");
    do
    {
        printf("Enter a token: ");                 
        scanf("%s",copy);
        strcpy(tokens,copy);
        if (strcmp(tokens,"end") == 0)
        {
            control = 0;
            result = pop();
            printf("\nResult is: %.2f\n\n",result);
        }
        else
            postfix_arithmetic(tokens);
        
    } while (control);
    
    return 0;
}
void push(float number)
{
    if (top >= dimension)
    {
        stack = (float*)realloc(stack,sizeof(float)*dimension*2);
        stack[top++] = number;
        dimension *= 2;
    }
    else
        stack[top++] = number;
    //printf("Boyut: %d\n",dimension);
}
float pop()
{
    if (top <= dimension/4)
    {
        stack = (float*)realloc(stack,sizeof(float)*dimension/2);
        dimension /= 2;
    }
    //printf("Boyut: %d\n",dimension);
    return stack[--top];
}
void print_Stack()
{
    int i;
    for ( i = 0; i < top; i++)
    {
         printf("%.2f \n",stack[i]);
    }
}
void postfix_arithmetic(char tokens[5])
{
     
    float number, val1, val2;
    int control = 1;
    if (isNumber(tokens[0]))
    {
        number = atof(tokens);
        push(number);
    }
    else
    {
        val2 = pop();
        val1 = pop();
        switch (tokens[0])
        {
        case '+': 
            push(val1 + val2); 
            break;
        case '-' :
            push(val1-val2);
            break;
        case '/':
            push( val1 / val2);
            break;
        case '*':
            push(val1 * val2);
            break;
        }
    }
}
int isNumber(char value)
{
    if(value <= '9' && value >= '0')
        return 1;
    return 0;
}
