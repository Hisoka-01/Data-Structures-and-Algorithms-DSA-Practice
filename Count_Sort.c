#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void traversal(int *ptr, int count)
{ // funtion to print the values of the given array
    for (int i = 0; i < count; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

int maximum(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int n)
{
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n);

    // Create the count array
    int *count = (int *)calloc((max + 1) * sizeof(int));

    // Initialize the array elements to 0

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array A

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[20]; // variable declearation
    int count;

    printf("Enter the length of the array\n");
    scanf("%d", &count); // taking the length of the array

    printf("Enter the elements of the array\n");
    for (int i = 0; i < count; i++) // accepting the elements
    {
        scanf("%d", &arr[i]);
    }
    printf("The values of array before sorting\n");
    traversal(arr, count); // function to print the values of the array

    countSort(arr, count); // function to sort the array

    printf("The values of array after sorting\n");
    traversal(arr, count);

    return 0;
}