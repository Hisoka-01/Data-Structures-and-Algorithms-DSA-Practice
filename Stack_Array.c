#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr){
    if (ptr->top==-1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack* ptr){
    if (ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* ptr, int val){
    if (isFull(ptr))
    {
        printf("STACK OVERFLOW :\n");
    }
    else
    {
        ptr->arr[++ptr->top]=val;
    }
    
}

 int pop(struct stack* ptr){
    if (isEmpty(ptr))
    {
        printf("STACK UNDERFLOW :\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top--];
    }
    
}

int peek(struct stack* ptr, int count){
    if (ptr->top-count+1 <0)
    {
        printf("Value Not Found\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top-count+1];
    }
    
}

int stackBottom(struct stack* ptr){
    if (isEmpty(ptr))
    {
        printf("STACK UNDERFLOW :\n");
        return -1;
    }
    return ptr->arr[0];
}

int stackTop(struct stack* ptr){
    return ptr->arr[ptr->top];
}

int main(int argc, char const *argv[])
{
    struct stack* s;
    s=(struct stack*)calloc(1,sizeof(struct stack*));
    printf("Enter the size of the array : \n");
    scanf("%d",&s->size);
    s->top = -1;
    s->arr = (int*)calloc(s->size,sizeof(int));

    //accepting values in the stack

    printf("Enter the no. of elements u want to push in the stuck :\n");
    int count;
    scanf("%d",&count);
    printf("Enter the elements :\n");
    for (int i = 0; i < count; i++)
    {
        int data;
        scanf("%d",&data);
        push(s, data);
    }

    //peeing after pushng the elements
    printf("Enter the no. of elements u want to peek at\n");
    int peekCount;
    scanf("%d",&peekCount);
    for (int i = peekCount ; i > 0 ; i--)
    {
        printf("Elements at index %d is %d\n",i,peek(s,i));
    }
    
    
    //taking out values from the stack
    printf("Enter the no. of elements to pop :\n");
    scanf("%d",&count);
    printf("The elements tthat got kicked out by you :\n");
    for (int i = 0; i < count; i++)
    {
        printf("Elements are : %d\n",pop(s));
    }

    printf("Enter the no of elements u want to peek at\n");
    scanf("%d",&peekCount);
    for (int i = peekCount ; i > 0 ; i--)
    {
        printf("Elements at index %d is %d\n",i,peek(s,i));
    }

    free(s->arr);
    free(s);

    return 0;
}
