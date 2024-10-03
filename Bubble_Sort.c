#include<stdio.h>

void traversal(int* ptr, int count){        //funtion to print the values of the given array
    for (int i = 0; i < count; i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

void bubbleSort(int* ptr, int count){                 //this is a adaptive version of bubble sort
    int temp;                                         //variable for taking values temporarily for swapping
    int isSorted = temp = 0;                          //counter to check if the array is sorted or not
    for (int i = 0; i < count-1; i++)
    {
        isSorted = 1;                                 
        for ( int j = 0; j < count-i-1; j++)
        {
            if ( ptr[j] > ptr[j+1])                  //checking if the elementss of the array are sorted or not
            {
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
                isSorted = 0;
            } 
        }
        if ( isSorted )                              //checking if the array is sorted or not
        {
            return;
        }
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
    traversal(arr, count);                         //function to print the values of the array
    bubbleSort(arr, count);                        //function to sort the array
    printf("The values of array after sorting\n"); 
    traversal(arr, count);                         //function the print the values of the array

    return 0;
}
