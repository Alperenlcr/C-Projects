#include<stdio.h>

int index_first(char letter)
{
    char big_letters[50][5] = {"A", "B", "C", "3", "D", "E", "F", "G", "8",
     "H", "I", "11", "J", "K"," L", "M", "N", "O", "18", "P",
      "R", "S", "22", "T", "U", "25" ,"V", "Y", "Z"};
    char small_letters[50][5] = {"a", "b", "c", "3", "d", "e", "f", "g", "8",
     "h", "10", "i", "j", "k", "l", "m", "n", "o" ,"18","p", "r", "s",
     "22", "t", "u", "25", "v", "y", "z"};

    char irregular_letters[2][8] = { {"Ç", "Ğ", "Ö", "Ş", "Ü", "İ"}, 
                                    {"ç", "ğ", "ö", "ş", "ü", "ı"} };

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// switch case ile irregular harf mi diye bakabilsem cozucem
// switch case ile baktiktan sonra varsa return licem
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    int i = 0;
    while (small_letters[i][0] != '\0')
    {
        if (small_letters[i][0] == letter || big_letters[i][0] == letter)
        {
            printf("%d",i);
            return i;
        }
        i++;
    }
    printf("\nError!!\n");
}

char** solution(char** words, int size)
{
// find the first word in the alphabet then print it and remove it
// return what is left
    int i, j, k, min_id, cmp_x;
    char* temp;

    // Find the minimum element in unsorted array
    min_id = index_first(words[0][0]);

    for (j = i+1; j < size; j++)
    {
        cmp_x = index_first(words[j][0]);
        if (cmp_x < min_id)
            min_id = j;

        // if first letter are same
        if (cmp_x == min_id)
        {
            k = 1;
            while (words[j][k] != '\0' || words[min_id][k] != '\0')
            {
                cmp_x = index_first(words[j][k]);
                min_id = index_first(words[i][k]);
                if (cmp_x < min_id)
                {
                    min_id = j;
                    break;
                }
            }
            // one of the words is shorter
            if (min_id != j && words[j][k] == '\0')
            {
                min_id = j;
            }
        }
    }
    // Remove the found minimum element
    printf("%s  ", words[min_id]);
    int u = 0;
    
    for ( i = min_id; i < size-1; i++)
    {
        words[i] = words[i+1];
    }
    words[size-1] = "ZZZZZZZZZZZZZ";
    return words;
    
}

void main () 
{
    char** names = {"İnci", "Büşra", "Buğra", "Ümit", "Ömer"};
    int i;
    for ( i = 5; i > 0; i--)
        names = solution(names, i);
}

