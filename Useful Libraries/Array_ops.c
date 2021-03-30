// ***READ ME***
// -------------
// * This codes includes some helpful functions about (static and dynamic) array operations *
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// merge_sort(array_name, 0, array_length-1)
// print_array(array_name, array_length)
// count(array_name, value)
// reverse(array_name, array_length)
// index_first(array_name, value)
// remove_first(array_name, array_length, value)
// set_unsorted(array_name, array_length)
// set_sorted(array_name, array_length)
// len(array_name)
// lineer_search(array_name, value)
// binary_search(array_name, 0, array_length-1, value)
// selection_sort(array, array_length)

#include <stdio.h>
#include <stdlib.h>
#define array_length 20

int len(int* Array)
{
    int count = 0;
    while (Array[count] != '\0')
    {
        count++;
    }
    return count+1;
}

int lineer_search(int* Array, int value)
{
    int i=0;
    while (Array[i] != value && Array[i] != '\0')
        i++;
    if (Array[i] == value)
        return 1;
    else
        return 0;
}

int* set_unsorted(int* Array, int size)
{
    int minus = 0, i, j;
    for ( i = 0; i < size; i++)
    {
        for ( j = i+1; j < size; j++)
        {
            if(Array[i] != -11 && Array[j] != -11 && Array[i] == Array[j])
            {
                Array[j] = -11;
                minus++;
            }
        }
    }

    int set_length = size - minus;
    int* set_arr;
    set_arr = (int*)malloc(set_length * sizeof(int));
    
    j = 0;
    for ( i = 0; i < size; i++)
    {
        if (Array[i] != -11)
        {
            set_arr[j] = Array[i];
            j++;
        }
    }
    return set_arr;
}

int* set_sorted(int* Array, int size)
{
    int minus = 0, i=0, j;
    while (i<size)
    {
        j = i+1;
        while (Array[i] == Array[j])
        {
            Array[j] = -11;
            minus++;
            j++;
        }
        i = j;
    }
    int set_length = size - minus;
    int* set_arr;
    set_arr = (int*)malloc(set_length * sizeof(int));
    
    j = 0;
    for ( i = 0; i < size; i++)
    {
        if (Array[i] != -11)
        {
            set_arr[j] = Array[i];
            j++;
        }
    }
    return set_arr;
}

int count(int* Array, int value)
{
    int i = 0, counter = 0;
    while (Array[i] != '\0')
    {
        if (Array[i] == value)
            counter++;
        i++;
    }
    return counter;
}

int index_first(int* Array, int value)
{
    int i = 0, index = -1;
    while (Array[i] != '\0')
    {
        if (Array[i] == value)
        {
            index = i;
            break;
        }
        i++;
    }
    return index;
}

void remove_first(int* Array, int size, int value)
{
    int i = 0, item_index;
    while (Array[i] != '\0')
    {
        if (Array[i] == value)
        {
            item_index = i;
            break;
        }
        i++;
    }
    for ( i = item_index; i < size-1; i++)
    {
        Array[i] = Array[i+1];
    }
    Array[size-1] = 0;
}

void merge(int* arr, int l, int m, int r)
{
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void merge_sort(int* arr, int l, int r)
{
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void reverse(int arr[], int start, int end)
{
/* Function to reverse arr[] from start to end*/
    int temp;
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   
}   

void print_array(int* A, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int binary_search(int* arr, int l, int r, int value)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == value)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > value)
			return binary_search(arr, l, mid - 1, value);

		// Else the element can only be present
		// in right subarray
		return binary_search(arr, mid + 1, r, value);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

void selection_sort(int* Array, int size)
{
    int i, j, min_id, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_id = i;
        for (j = i+1; j < size; j++)
          if (Array[j] < Array[min_id])
            min_id = j;

        // Swap the found minimum element with the first elemen
        temp = Array[min_id];
        Array[min_id] = Array[i];
        Array[i] = temp;
    }
}

void main()
{
// defining static_array and dynamic_array
    int static_array[20] = {23,345,423,2412,3,342,5,12,31231,423,1,1,1,3,2,-5,-8,123,423,423};
    int* dynamic_array;
    int i;
    dynamic_array = (int*)malloc(array_length * sizeof(int));
    for ( i = 0; i < array_length; i++)
        *(dynamic_array+i) = static_array[i];
// end
    printf("\n");
// static_array length
    int static_array_length = sizeof(static_array) / sizeof(static_array[0]);
    printf("\nstatic array length : %d\n",static_array_length);
// end
printf("\n");
// sending parameters binary_search()
    printf("binary_search\n");
    printf("423 is in array ? : %d\n", binary_search(static_array, 0, array_length-1, 423));
    printf("3 is in array ? : %d\n", binary_search(dynamic_array, 0, array_length-1, 3));
// end
    printf("\n");
// sending parameters merge_sort() and print_array() -Static-
    printf("Given static_array is \n");
    print_array(static_array, static_array_length);
 
    merge_sort(static_array, 0, static_array_length - 1);
 
    printf("\nSorted static_array is \n");
    print_array(static_array, static_array_length);
    printf("\n******************\n");
// end
    printf("\n");
// sending parameters merge_sort and print_array() -Dynamic-
    int dynamic_array_length = array_length;
    printf("Given dynamic_array is \n");
    print_array(dynamic_array, dynamic_array_length);
 
    merge_sort(dynamic_array, 0, dynamic_array_length - 1);
 
    printf("\nSorted dynamic_array is \n");
    print_array(dynamic_array, dynamic_array_length);
// end
    printf("\n");
// sending parameters count()
    printf("count() for 3 : %d\n", count(dynamic_array, 3));
    printf("count() for 423 : %d\n", count(static_array, 423));
// end
    printf("\n");
// sending parameters set_sorted()
    static_array_length = sizeof(static_array) / sizeof(static_array[0]);
    int* set_sorted_static_array = set_sorted(static_array, static_array_length);
    printf("Set static_array is \n");
    int set_sorted_static_array_length = len(set_sorted_static_array);
    print_array(set_sorted_static_array, set_sorted_static_array_length-2);

    int* set_sorted_dynamic_array = set_sorted(dynamic_array, dynamic_array_length);
    int set__sorted_dynamic_array_length = len(set_sorted_dynamic_array);
    printf("Set dynamic_array is \n");
    print_array(set_sorted_dynamic_array, set__sorted_dynamic_array_length-2);
//end
    printf("\n");
// sending parameters reverse()
    static_array_length = sizeof(static_array) / sizeof(static_array[0]);
    reverse(static_array, 0, static_array_length-1);
    printf("Reversed static_array is \n");
    print_array(static_array, static_array_length);

    dynamic_array_length = array_length;
    reverse(dynamic_array, 0, dynamic_array_length-1);
    printf("Reversed dynamic_array is \n");
    print_array(dynamic_array, dynamic_array_length);
//end
    printf("\n");
// sending parameters merge_sort and print_array() -Dynamic-
    dynamic_array_length = array_length;
    selection_sort(dynamic_array, dynamic_array_length);
    printf("selection_sort() dynamic_array is \n");
    print_array(dynamic_array, dynamic_array_length);
// end
    printf("\n");
// sending parameters index_first()
    printf("first index 3 : %d\n", index_first(dynamic_array, 3));
    printf("first index 423: %d\n", index_first(static_array, 423));
// end
    printf("\n");
// sending parameters remove()
    static_array_length = sizeof(static_array) / sizeof(static_array[0]);
    remove_first(static_array, static_array_length, 31231);
    printf("31231 Removed static_array is \n");
    print_array(static_array, static_array_length);

    dynamic_array_length = array_length;
    remove_first(dynamic_array, dynamic_array_length, 423);
    printf("423 Removed dynamic_array is \n");
    print_array(dynamic_array, dynamic_array_length);
//end
    printf("\n");
// sending parameters set_unsorted()
    static_array_length = sizeof(static_array) / sizeof(static_array[0]);
    int* set_static_array = set_unsorted(static_array, static_array_length);
    printf("Set static_array is \n");
    int set_static_array_length = len(set_static_array);
    print_array(set_static_array, set_static_array_length);

    int* set_dynamic_array = set_unsorted(dynamic_array, dynamic_array_length);
    int set_dynamic_array_length = len(set_dynamic_array);
    printf("Set dynamic_array is \n");
    print_array(set_dynamic_array, set_dynamic_array_length);
//end
// sending parameters lineer_search()
    printf("lineer_search\n");
    printf("3 is in array ? : %d\n", lineer_search(static_array, 3));
    printf("4 is in array ? : %d\n", lineer_search(dynamic_array, 4));
// end

free(dynamic_array);
free(set_dynamic_array);
free(set_static_array);
free(set_sorted_static_array);
free(set_sorted_dynamic_array);
}