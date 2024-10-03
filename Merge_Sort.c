#include <stdio.h>

void traversal(int *ptr, int count)
{ // funtion to print the values of the given array
    for (int i = 0; i < count; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void merge(int *arr, int mid, int low, int high)     //function to merge two sorted array
{
    int i, j, k;                                     //variable decleration
    int A[100];
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)                    //sorting the elements of both the sorted array
    {
        if (arr[i] < arr[j])                         //check which one is smalleer
        {
            A[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            A[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)                                //addomg the remaining elements of the array
    {
        A[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)                               //addomg the remaining elements of the array
    {
        A[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)                //transfering the elements from sorted array to original array
    {
        arr[i] = A[i];
    }
}

void mergeSort(int *arr, int low, int high)        //recursive fucntion to sort the array by merging sorted array
{
    int mid;                                       //variable decleration
    if (high > low)                        
    {
        mid = (high + low) / 2;                   //finding the mid position to seprate and sort the array 
        mergeSort(arr, low, mid);                 //further separating the array to sort it until there is only two elemetns
        mergeSort(arr, mid + 1, high);
        merge(arr, mid, low, high);               //merging th esorted array
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
    traversal(arr, count); // function to print the values of the array(before sort)

    mergeSort(arr, 0, count - 1); // function to sort the array

    printf("The values of array after sorting\n");
    traversal(arr, count); // function to print the values of the array(after sort)

    return 0;
}

// Here in merge sort we break the array from middle reusively until there are only two elements left and then we merge and sort it from there to the orginal array