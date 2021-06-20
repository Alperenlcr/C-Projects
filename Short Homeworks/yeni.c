#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200

struct position{
    int x;
    int y;
};

struct characters{
    char char_name;
    struct position p;
}array[MAX];

int search(int i, int j, int count, int yaz)
{
    int k;
    for ( k = 0; k < count; k++)
    {
        if (array[k].p.x == i && array[k].p.y == j)
        {
            if (yaz)
                printf("%c", array[k].char_name);
            return 1;
        }
    }
    return 0;
}

void fillTheChars(int col, int row, int count)
{
	int i, a, b;
	for(i=0;i<count;i++)
    {
		array[i].char_name = 'A'+rand()%26;
        do
        {
            a = rand()%row;
            b = rand()%col;
        } while (search(a, b, count, 0));
        array[i].p.x = a;
        array[i].p.y = b;    
	}
}

void display(int col,int row, int count)
{
	int i, j;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            if (! search(i, j, count, 1))
                printf("%c", -49);            
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int col, row, count;
	printf("Enter the sizes of the matris(row-col): ");
	scanf("%d %d",&row, &col);
	
	printf("Enter the character count: ");
	scanf("%d",&count);
	fillTheChars(col, row, count);
    display(col, row, count);
    return 0;
}