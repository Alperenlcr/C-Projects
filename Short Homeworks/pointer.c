#include <stdio.h>
void f(int value, int *values_adress, int *amp_value, int **amp_values_adress, int tercih)
{
    switch (tercih)
    {
    case 1:
        value = 6;
        break;
    
    case 2:
        *values_adress = 6;
        break;
    
    case 3:
        *amp_value = 6;
        break;
    
    case 4:
        **amp_values_adress = 6;
        break;
    }
}

void main()
{
    int value, *values_adress;
    int **adress_adress;

    value = 3;
    values_adress = &value;
    adress_adress = &values_adress;
    printf("%p  %d\n", values_adress, value);
    printf("%p  %d\n", &value, *values_adress);
    printf("%p  %p   %d\n", &values_adress, *adress_adress, **adress_adress);

    f(value, values_adress, &value, &values_adress, 2);

    printf("%p  %d\n", values_adress, value);


}