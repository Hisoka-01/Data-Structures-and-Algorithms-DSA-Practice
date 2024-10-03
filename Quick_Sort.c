#include<stdio.h>

void traversal(int* ptr, int count){        //funtion to print the values of the given array
    for (int i = 0; i < count; i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

int partition(int* arr, int low, int high){
    int temp;
    int pivot = arr[low];
    int i= low + 1;
    int j = high;
    do
    {
        while ( arr[i] <= pivot && i<=high)
        {
            i++;                     //increasing i till a number is found which is greater than pivot
        }
        while ( arr[j] >= pivot && j>=low+1)
        {
            j--;                     //decreasing j till a number is found which is lesser than pivot
        }
        if ( i < j )
        {
            temp = arr[i];               //upon finding those both number we will swap them 
            arr[i]  = arr[j];
            arr[j]  = temp;
        }
    } while ( i < j );

    temp = arr[low];            //swap pivot with arr[j] 
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int* arr, int low, int high){
    int partitionIndex;                      //variable decleration

    if( low < high ){
    partitionIndex = partition(arr, low, high);  //sorting element in pivot and getting its new index
    quickSort(arr, low, partitionIndex-1);   //calling quicksort again to sort the elements in the left side of the sorted element
    quickSort(arr, partitionIndex+1,high);   //calling quicksort again to sort the elements in the right side of the sorted element
    }
}

int main(int argc, char const *argv[])
{
    int arr[20];                                   //variable declearation
    int count;

    printf("Enter the length of the array\n");
    scanf("%d",&count);                            //taking the length of the array

    printf("Enter the elements of the array\n");
    for (int i = 0; i < count; i++)                //accepting the elements
    {
        scanf("%d",&arr[i]);
    }
    printf("The values of array before sorting\n");
    traversal(arr, count);                         //function to print the values of the array(before sort)

    quickSort(arr,0,count-1);                       //function to sort the array

    printf("The values of array after sorting\n"); 
    traversal(arr, count);                         //function to print the values of the array(after sort)

    return 0;
}