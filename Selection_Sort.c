#include<stdio.h>

void traversal(int* ptr, int count){        //funtion to print the values of the given array
    for (int i = 0; i < count; i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
}

void selectionSort(int* ptr, int count){    //function to sort the array using selection sort
    int min = 0;
    int temp = 0;
    for (int i = 0; i < count-1; i++)
    {
        min = i;                            //reset the value of the counter
        for (int j = i+1; j < count; j++)
        {
            if ( ptr[j] < ptr[i])           //cheking if the elements are sorted or not
            {
                min = j;                
            }
        }
    temp = ptr[i];                          //sorting the elelments
    ptr[i] = ptr[min];
    ptr[min] = temp;
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

    selectionSort(arr, count);                        //function to sort the array

    printf("The values of array after sorting\n"); 
    traversal(arr, count);                         //function to print the values of the array(after sort)

    return 0;
}
