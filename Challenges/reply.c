#include <stdio.h>
#include <stdlib.h> // For exit() function


void selection_sort_b(int* Array, int size)
{
    long i, j, min_id, temp;
    int k;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i+=3)
    {
        // Find the minimum element in unsorted array
        min_id = i;
        for (j = i+3; j < size; j+=3)
          if (Array[j] < Array[min_id])
            min_id = j;

        // Swap the found minimum element with the first elemen
        for (k = 0; k < 3; k++)
        {
            temp = Array[min_id+k];
            Array[min_id+k] = Array[i+k];
            Array[i+k] = temp;   
        }
    }
}

void selection_sort_a(int* Array, int size)
{
    long i, j, min_id, temp;
    int k;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i+=2)
    {
        // Find the minimum element in unsorted array
        min_id = i;
        for (j = i+2; j < size; j+=2)
          if (Array[j] < Array[min_id])
            min_id = j;

        // Swap the found minimum element with the first elemen
        for (k = 0; k < 2; k++)
        {
            temp = Array[min_id+k];
            Array[min_id+k] = Array[i+k];
            Array[i+k] = temp;   
        }
    }
}


int count=0;
void main()
{
    //*************************************************
    // READ INPUT
    //*************************************************
    long N, M, sum=0;
    int W, H, unnecessary, unnecessary2;
    long i;
    int* Building_c_x_y;
    int* antenna_c_index;
    char* input_files[6] = {
    "data_scenarios_a_example.in",      "data_scenarios_b_mumbai.in", 
    "data_scenarios_c_metropolis.in",   "data_scenarios_d_polynesia.in",
    "data_scenarios_e_sanfrancisco.in", "data_scenarios_f_tokyo.in"
    };
    char* output_files[6] = {
    "result_a_example.in",      "result_b_mumbai.in", 
    "result_c_metropolis.in",   "result_d_polynesia.in",
    "result_e_sanfrancisco.in", "result_f_tokyo.in"
    };
    FILE *file_read_pointer;
    if ((file_read_pointer = fopen(input_files[count], "r")) == NULL) {
        printf("Error! opening file\n");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    fscanf(file_read_pointer, "%d %d", &W, &H);
    fscanf(file_read_pointer, "%ld %ld %d", &N, &M, &unnecessary);

    Building_c_x_y = (int *)malloc(N * 3 * sizeof(int));
    antenna_c_index = (int *)malloc(M * 2 * sizeof(int));

    for ( i = 0; i < N; i++)
    {
        fscanf(file_read_pointer, "%d %d %d %d", &Building_c_x_y[3*i+1], &Building_c_x_y[3*i+2], &unnecessary, &unnecessary2);
        sum += unnecessary2;
        Building_c_x_y[3*i] = unnecessary2;
    }

    for ( i = 0; i < M; i++)
    {
        fscanf(file_read_pointer, "%d %d", &unnecessary2 ,&unnecessary);
        antenna_c_index[i*2] = unnecessary;
        antenna_c_index[i*2+1] = i;
    }
    //*************************************************
    // END OF READING INPUT
    //*************************************************
    
//-------------------------------------------------

    //*************************************************
    // SOLUTION
    //*************************************************
    selection_sort_b(Building_c_x_y, N*3);
    selection_sort_a(antenna_c_index, M*2);

    long j = 0;

    FILE *file_write_pointer;
    file_write_pointer = fopen(output_files[count], "w");
    fprintf(file_write_pointer, "%ld\n", M);

    for ( i = 0; i < M; i++)
    {
        j = antenna_c_index[2*i+1];
        fprintf(file_write_pointer, "%ld %d %d\n", i, Building_c_x_y[3*j+1], Building_c_x_y[3*j+2]);
    }
    //*************************************************
    // END OF SOLUTION
    //*************************************************
    count++;
    printf("%d. round is completed. Success !!\n", count);
    if(count<6)
        main();
}