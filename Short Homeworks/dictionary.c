#include<stdio.h>
int main()
{
    int N,min,i,j,k,l;
    char dictionary[20][20];
    printf("Use uppercase letters every time.\n");
    printf("How many words ?\n");
    scanf("%d",&N);
    for ( i = 0; i < N; i++)
    {
        printf("%d . word >>> ",i+1);
        scanf("%s",&dictionary[i]);    //taking words to matrix
    }

    //sorting alphabetical
    int column,x;
    char tmp[20];
    for ( l = 0; l < N-1; l++)
    {
        min = l;
        for ( k = l+1; k < N; k++)
        {
            column = 0;
            while (dictionary[min][column] == dictionary[k][column]) //preparation for comparison
            {
                column++;
            }
            if (dictionary[k][column] == '\0' || ( dictionary[min][column] != '\0' && dictionary[min][column]>dictionary[k][column] ))  //comparison
            {
                min = k;
            }
        }
        //assign
        if (min != l)
        {
            x = 0;
            while (dictionary[min][x] != '\0')
            {
                tmp[x] = dictionary[min][x];
                x++;
            }
            tmp[x] = '\0';
            x = 0;
            while (dictionary[l][x] != '\0')
            {
                dictionary[min][x] = dictionary[l][x];
                x++; 
            }
            dictionary[min][x] = '\0';
            x = 0;
            while (tmp[x] != '\0')
            {
                dictionary[l][x] = tmp[x];
                x++;
            }
            dictionary[l][x] = '\0';
        }
    }
    // output
    printf("\nsorted dictionary");
    for (i = 0; i < N; i++)
    {
        printf("\n%s",dictionary[i]);
    }
    //int array for keeping first letters information
    int alphabet[26],letter;
    for (i = 1; i <= 26; i++)
    {
        alphabet[i] = 0;
    }
    printf("\nStarting Positions of Letters >>> ");
    for ( j = 0; j < N; j++)
    {
        letter = dictionary[j][0]-'A'+1;
        if (alphabet[letter] == 0)
        {
            alphabet[letter] = j+1;
            //Starting Positions of Letters
            printf("%c:%d\t",dictionary[j][0],j+1);
        }
    }

    char word[20],another = 'Y';
    int search_steps,found;
    while (another == 'Y')
    {
        //taking a word to search in matrix
        printf("\nEnter a word to search in dictionary : ");
        scanf("%s",&word);
        //and searching
        found = 0;
        search_steps = 1;
        if(alphabet[(word[0]-'A'+1)] != 0)
        {
            j = alphabet[(word[0]-'A'+1)]-1;
            while(found == 0 && j<=N && dictionary[j][0] == word[0])
            {
                k = 1;
                while (dictionary[j][k] == word[k] && word[k] !=  '\0')
                {
                    k++;
                }
                if (word[k] == '\0' && dictionary[j][k] == '\0')
                {
                    found = 1;
                }
                else
                {
                    j++;
                    search_steps++;
                }
            }
        }
        if (found == 1)
        {
            printf("'%s' is in the dictionary.",word);
        }
        else
        {
            printf("'%s' is not in the dictionary.",word);
        }
        printf("\nNumber of Search Steps: %d",search_steps);
        printf("\nDo you want to search another word (Y or N) :");
        scanf(" %c",&another);
    }
    return 0;  
}