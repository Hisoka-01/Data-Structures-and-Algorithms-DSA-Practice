#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int tsize;
    int used_size;
    int *ptr;
};

void createarray(struct myArray *a, int l, int k){
    //(*a).tsize=l;
    //(*a).used_size=k;
    //(*a).ptr=(*int)calloc(l,sizeof(int));

    //we can write (*a).ptr as a->

    a->tsize=l;
    a->used_size=k;
    a->ptr = (int*)calloc(l,sizeof(int));

}

 void setval(struct myArray *a){
     for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d",a->ptr+i);
    }
 }

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n",*(a->ptr+i));
    }
    
}

int main(int argc, char const *argv[])
{
    struct myArray marks;
    int len,usage;
    printf("Enter the length of the array and the no. of elements you wish to use first\n");
    scanf("%d\n%d",&len,&usage);
    createarray(&marks,len,usage);
    setval(&marks);
    show(&marks);
    free(marks.ptr);
    return 0;
}