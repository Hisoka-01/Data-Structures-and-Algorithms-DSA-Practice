#include<stdio.h>
#include<stdlib.h>

void input(int* p, int count){
    printf("Now enter the elements :\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d",p+i);
    }
}

void insertion(int* p, int capacity, int* count, int element, int index){
    if (capacity==*count)
    {
        printf("The array is alread full !\n");
    }else{
        for (int i = *count-1; i >= index-1; i--)
        {
            *(p+i+1)=*(p+i);
        }
        *(p+index-1)=element;
        (*count)++;
        printf("Insertion succesful\n");
    }
    
}

void deletion(int* p, int* count, int index){
    if (index>*count)
    {
        printf("The given index has no element !\n");
    }else{
        for (int i = index-1; i <*count-1; i--)
        {
            *(p+i)=*(p+i+1);
        }
        (*count)--;
        printf("deletion succesful\n");
    }
    
}

void linearSearch(int* p, int* count, int element){
    int k=0;
    for (int i = 0; i < *count; i++)
    {
        if (*(p+i) == element)
        {
            printf("Position of the given element is : %d\n",i+1);
            k++;
            break;
        }
        
    }
    if (k==0)
    {
        printf("Element not found");
    }
    
}

void binarySearch(int* p, int* conunt, int element){
    int low=0, High=*conunt-1, mid;
    int k=0;
    while (low<=High)
    {
        mid= (low+High)/2;
        if (*(p+mid)==element)
        {
            printf("Element found at : %d",mid+1);
            k++;
            break;
        }
        else if (element> *(p+mid))
        {
            low=mid+1;
        }else{
            High=mid-1 ;
        }
    }
    if (k==0)
    {
        printf("Element not found");
    }
    

}

void show(int* p, int count){
    printf("The valus are :\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\n",*(p+i));
    }
}

int main(int argc, char const *argv[])
{
    int arr[5];
    int len = sizeof(arr)/sizeof(int);
    printf("%d\n",len);
    int usage;
    printf("Enter the no. of elements u want to input initially : \n");
    scanf("%d",&usage);
    input(arr,usage);
    show(arr,usage);

    /*insertion of a number

    printf("Enter the element u want to add with its positon : \n");
    int elem,ind;
    scanf("%d%d",&elem,&ind);
    insertion(arr,len,&usage,elem,ind);
    show(arr,usage);
    */

    /*deletion

    printf("Enteh the index of the element u want to delete : \n");
    int del;
    scanf("%d",&del);
    deletion(arr,&usage,del);
    show(arr,usage);
    */

   /*Linear Search
    printf("Enter the element u want to find by linear search : \n");
    int dk;
    scanf("%d",&dk);
    linearSearch(arr,&usage,dk);
    */
    /*Binary Search
    printf("Enter the element u want to find by binary search : \n");
    int bk;
    scanf("%d",&bk);
    binarySearch(arr,&usage,bk);
    */
   
    return 0;
}
