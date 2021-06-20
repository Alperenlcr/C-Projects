#include <stdio.h>

void orijineEnYakin(int, int, int, int, int, int);

int main()
{
    orijineEnYakin(3, 3, 7, 7, 9, 9);
    return 0;
}

void orijineEnYakin(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if ( (x1*x1 + y1*y1) < (x2*x2 + y2*y2) && (x1*x1 + y1*y1) < (x3*x3 + y3*y3) )
        printf("Yakin olan : (%d, %d)", x1, y1);
    
    else if ( (x2*x2 + y2*y2) < (x3*x3 + y3*y3) )
        printf("Yakin olan : (%d, %d)", x2, y2);
    
    else
        printf("Yakin olan : (%d, %d)", x3, y3);
}