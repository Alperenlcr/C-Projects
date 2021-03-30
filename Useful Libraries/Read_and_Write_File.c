#include <stdio.h>
#include <stdlib.h> // For exit() function
# define elements 10
struct struct_name
{
    int number;
    char string[20];
    float floating;
}data_keeper[elements];

void main()
{
/*
********FILE********
row_count column_count
float float float
float float float
float float float
float float float
float float float
array_length
int int int int int int
string
data_count
struct_data_1 struct_data_2 struct_data_3
struct_data_1 struct_data_2 struct_data_3
struct_data_1 struct_data_2 struct_data_3
struct_data_1 struct_data_2 struct_data_3
*/
    //*************************************************
    // READ INPUT
    //*************************************************
    int row_count, column_count, array_length, data_count, i;
    int *dynamic_array;
    float *dynamic_matrix;
    char* input_files[2] = {"input_file1.txt", "input_file1.txt"};
    char* output_files[2] = {"output_file1.txt", "output_file1.txt"};

    // Opening file
    FILE *file_read_pointer;
    if ((file_read_pointer = fopen(input_files[0], "r")) == NULL) {
        printf("\nError! opening file\n");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // Reading matrix
    fscanf(file_read_pointer, "%d %d\n", &row_count, &column_count);
    dynamic_matrix = (float *)malloc(row_count * column_count * sizeof(float)); 

    for ( i = 0; i < row_count; i++)
    {
        fscanf(file_read_pointer, "%f %f %f\n", 
        (dynamic_matrix + i*column_count + 0), 
        (dynamic_matrix + i*column_count + 1), 
        (dynamic_matrix + i*column_count + 2) );
    }


    // Reading array
    fscanf(file_read_pointer, "%d\n", &array_length);
    dynamic_array = (int*)malloc(array_length * sizeof(int));

    for ( i = 0; i <  array_length; i++)
        fscanf(file_read_pointer, "%d", (dynamic_array + i));
    fscanf(file_read_pointer, "\n");
    
    // Reading string
    char string[1000];
    fscanf(file_read_pointer, "%[^\n]", string);

    // Reading struct
    fscanf(file_read_pointer, "%d", &data_count);
    for ( i = 0; i < data_count; i++)
    {
        fscanf(file_read_pointer, "%d %s %f", &data_keeper[i].number, data_keeper[i].string, &data_keeper[i].floating);
    }
    //*************************************************
    // END OF READING INPUT
    //*************************************************
    
//-------------------------------------------------

    //*************************************************
    // SOLUTION
    //*************************************************
// Do your thing
    //*************************************************
    // END OF SOLUTION
    //*************************************************

//-------------------------------------------------

    //*************************************************
    // WRITE OUTPUT
    //*************************************************
    
    // Creating file
    FILE *file_write_pointer;
    file_write_pointer = fopen(output_files[0], "w");

    // Writing matrix
    fprintf(file_write_pointer, "%d %d\n", row_count, column_count);
    for ( i = 0; i < row_count; i++)
    {
        fprintf(file_write_pointer, "%.2f %.2f %.2f\n", 
        dynamic_matrix[i*column_count + 0], 
        dynamic_matrix[i*column_count + 1], 
        dynamic_matrix[i*column_count + 2] );
    }

    // Writing array
    fprintf(file_write_pointer, "%d\n", array_length);

    for ( i = 0; i <  array_length; i++)
        fprintf(file_write_pointer, "%d ", *(dynamic_array+i));
    fprintf(file_write_pointer, "\n");
    
    // Writing string
    fprintf(file_write_pointer, "%s\n", string);

    // Writing struct
    fprintf(file_write_pointer, "%d\n", data_count);
    for ( i = 0; i < data_count; i++)
    {
        fprintf(file_write_pointer, "%d %s %.2f\n", data_keeper[i].number, data_keeper[i].string, data_keeper[i].floating);
    }
    printf("\nEverthing is fine !!\n\n");
    //*************************************************
    // END OF WRITING OUTPUT
    //*************************************************
    free(dynamic_array);
    free(dynamic_matrix);
}