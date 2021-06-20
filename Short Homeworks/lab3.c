#include<stdio.h>
#include<string.h>
#define MAX 50

void solution(int x0, int y0, int x1, int y1, int matrix[MAX][MAX], int sum)
{
// secenekleri elde etme
    int yatay, dikey, i;
    char yazi[15];

    if (x0 == x1)    // ayni yatayda
        dikey = 0;
    else if (x0 < x1)    // end asagida
        dikey = 1;
    else        // end yukarida
        dikey = -1;

    if (y0 == y1)    // ayni dikeyde
        yatay = 0;
    else if (y0 < y1)    // end sagda
        yatay = 1;
    else        // end solda
        yatay = -1;

    // seceneklerden tercih yapma
//current place : x0 y0 Board Value : matrix[x0][y0]    Current total : sum \n Next move : %s\n
    if (dikey == 0 && yatay == 0)
    {
        return;
    }
    
    else if (dikey == 0)     // hedefle ayni satirda
    {
        if(yatay == 1)
            strcpy(yazi, "sag");
        else
            strcpy(yazi, "sol");
        x0 += yatay;
    }
    else if(yatay == 0)     // hedefle ayni sutunda
    {
        if(dikey == 1)
            strcpy(yazi, "asagi");
        else
            strcpy(yazi, "yukari");
        y0 += dikey;
    }
    else if (matrix[x0][y0+yatay] < matrix[x0+dikey][y0])     // yatayda hareket yapacak
    {
        y0 += yatay;
        if (yatay == 1)
            strcpy(yazi, "sag");
        else
            strcpy(yazi, "sol");
    }
    else    // dikeyde hareket yapacak
    {
        x0 += dikey;
        if (dikey == 1)
            strcpy(yazi, "asagi");
        else
            strcpy(yazi, "yukari");
    }
    printf("Played move : %s   Next place : %d %d  Next board Value : %d    Current total : %d \n", yazi, x0, y0, matrix[x0][y0], sum);

    solution(x0, y0, x1, y1, matrix, sum);
}

int main()
{
    int Board[MAX][MAX]={
        {0,5,30,-20,40},
        {20,-10,10,5,50},
        {5,50,-40,15,60},
        {10,-10,10,-5,70},
        {15,20,30,-20,0}};
    int i, j, n;
    int x0, y0, x1, y1, first=0;
    printf("\nN : ");
    scanf("%d", &n);
    do
    {
        if (first)
            printf("Wrong, try again.\n");
        first = 1;
        
        printf("Start (space separated): ");
        scanf("%d %d", &x0, &y0);
    } while (Board[x0][y0] != 0 || x0>=n || y0>=n);
    first = 0;
    do
    {
        if (first)
            printf("Wrong, try again.\n");
        first = 1;

        printf("End (space separated): ");
        scanf("%d %d", &x1, &y1);
    } while (Board[x1][y1] != 0 || x1>=n || y1>=n);
    
    // solution
    printf("\nHedefe varista izlenen guzergah asagidaki gibidir.\n");
    solution(x0, y0, x1, y1, Board, 0);
    printf("\n");
    



    return 0;
}


































#include<stdio.h>
#include<string.h>
#define MAX 50

void solution(int* x0, int* y0, int x1, int y1, int matrix[MAX][MAX])
{
// secenekleri elde etme
    int yatay, dikey, i;
    if (*x0 == x1)    // ayni yatayda
        dikey = 0;
    else if (*x0 < x1)    // end asagida
        dikey = 1;
    else        // end yukarida
        dikey = -1;

    if (*y0 == y1)    // ayni dikeyde
        yatay = 0;
    else if (*y0 < y1)    // end sagda
        yatay = 1;
    else        // end solda
        yatay = -1;

    // seceneklerden tercih yapma
    
    if (dikey == 0)     // hedefle ayni satirda
    {
        char yazi[10];
        if(yatay == 1)
            strcpy(yazi, "sag");
        else
            strcpy(yazi, "sol");

        for (i = 0; i < x1 - *x0; i++)
            printf("%s ", yazi);
        
        return;
    }
    else if(yatay == 0)     // hedefle ayni sutunda
    {
        char yazi[10];
        if(dikey == 1)
            strcpy(yazi, "asagi");
        else
            strcpy(yazi, "asagi");

        for (i = 0; i < y1 - *y0; i++)
            printf("%s ", yazi);
        
        return;
    }
    else if (matrix[*x0][*y0+yatay] < matrix[*x0+dikey][*y0])     // yatayda hareket yapacak
    {
        *y0 += yatay;
        if (yatay == 1)
            printf("sag ");
        else
            printf("sol ");
    }
    else    // dikeyde hareket yapacak
    {
        *x0 += dikey;
        if (dikey == 1)
            printf("asagi ");
        else
            printf("yukari ");
    }
    solution(x0, y0, x1, y1, matrix);
}

int main()
{
    int Board[MAX][MAX]={
        {0,5,30,-20,40},
        {20,-10,10,5,50},
        {5,50,-40,15,60},
        {10,-10,10,-5,70},
        {15,20,30,-20,0}};
    int i, j, n;
    int x0, y0, x1, y1, first=0;
    printf("\nN : ");
    scanf("%d", &n);
    do
    {
        if (first)
            printf("Wrong, try again.\n");
        first = 1;
        
        printf("Start (space separated): ");
        scanf("%d %d", &x0, &y0);
    } while (Board[x0][y0] != 0 || x0>=n || y0>=n);
    first = 0;
    do
    {
        if (first)
            printf("Wrong, try again.\n");
        first = 1;

        printf("End (space separated): ");
        scanf("%d %d", &x1, &y1);
    } while (Board[x1][y1] != 0 || x1>=n || y1>=n);
    
    // solution
    printf("\nHedefe varista izlenen guzergah asagidaki gibidir.\n");
    solution(&x0, &y0, x1, y1, Board);
    printf("\n");
    
//current place : x0 y0 Board Value : matrix[x0][y0]    Current total : sum \n Next move : %s\n



    return 0;
}

