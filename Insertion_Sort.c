#include<stdio.h>

void traversal(int* ptr, int count){        //funtion to print the values of the given array
    for (int i = 0; i < count; i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

void insertionSort(int* ptr, int count){
    int key = 0;
    int j = 0;
    for (int i = 1; i <= count-1; i++)
    {
        key = ptr[i];
        j = i-1;
        while ( j >=0 && ptr[j] > key)
        {
            ptr[j+1] = ptr[j];
            j--;
        }
        ptr[j+1] = key;
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

    insertionSort(arr, count);                        //function to sort the array

    printf("The values of array after sorting\n"); 
    traversal(arr, count);                         //function to print the values of the array(after sort)

    return 0;
}
