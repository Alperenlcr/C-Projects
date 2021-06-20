#include <stdio.h>
#include<stdlib.h>
#define MAX 50
int main()
{
    int row_count, column_count, i, j, round;
    int *dynamic_matrix;

    FILE *file_read_pointer;
    if ((file_read_pointer = fopen("Compressed.txt", "r")) == NULL) {
        printf("\nError! opening file\n");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
    // Reading matrix
    fscanf(file_read_pointer, "%d %d\n%d\n", &row_count, &column_count, &round);
    dynamic_matrix = (int *)malloc(round * 3 * sizeof(int)); 

    for ( i = 0; i < round; i++)
    {
        fscanf(file_read_pointer, "%d %d %d\n", 
        (dynamic_matrix + i*3 + 0), 
        (dynamic_matrix + i*3 + 1), 
        (dynamic_matrix + i*3 + 2) );
    }
    /*
    for (int i = 0; i < round; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", dynamic_matrix[i*3 + j]);
        }
        printf("\n");
    }
    */
    // create matrix
    int matrix[MAX][MAX];
    for ( i = 0; i < row_count; i++)
    {
        for ( j = 0; j < column_count; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for ( i = 0; i < round; i++)
    {
        matrix[dynamic_matrix[i*3+0]][dynamic_matrix[i*3+1]] = dynamic_matrix[i*3+2];
    }
    /*
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < column_count; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    */
    FILE *file_write_pointer;
    file_write_pointer = fopen("Matrix.txt", "w");

    // Writing matrix
    fprintf(file_write_pointer, "%d %d\n", row_count, column_count);
    for ( i = 0; i < row_count; i++)
    {
        for ( j = 0; j < column_count; j++)
        {
            fprintf(file_write_pointer, "%d ", matrix[i][j]);
        }
        fprintf(file_write_pointer, "\n");
    }
    free(dynamic_matrix);

    return 0;
}