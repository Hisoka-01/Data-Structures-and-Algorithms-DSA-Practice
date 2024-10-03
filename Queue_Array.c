#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int* arr;
};

int isFULL(struct Queue* ptr){
    if (ptr->rear == ptr->size-1)
    {
        return 1;
    }
    return 0;
}

int isEMPTY( struct Queue* ptr){
    if ( ptr->front == ptr->rear  )
    {
        printf(" Queue is Full\n");
        return 1;
    }
    return 0;
}

void enQueue( struct Queue* ptr, int val){
    if ( isFULL(ptr))
    {
        printf(" No elements can be insereted as the queue is already full\n");
    }
    else
    {
        ptr->arr[++ptr->rear] = val;
    }
}

int deQueue(struct Queue* ptr){
    int a = -1;
    if ( isEMPTY(ptr) )
    {
        printf(" The queue is already empty so no element can be taken out\n");
        return a;
    }
    a = ptr->arr[++ptr->front];
    return a;
}

int main(int argc, char const *argv[])
{
    struct Queue q;
    int count;

    printf(" Enter the length of the queue\n");
    scanf("%d",&count);
    q.size = count;
    q.front = q.rear = -1;
    q.arr = (int*)calloc(q.size, sizeof(int));

    //Insertion
    printf("Entere the number of elements u wwant to put in queue\n");
    int value;
    scanf("%d",&count);
    printf("Enter the elements\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d",&value);
        enQueue(&q,value);
    }
    printf(" The frnt and rear are : %d and %d\n", q.front, q.rear);

    //Deleltion
    printf("Entere the number of elements u wwant to take out from the queue\n");
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        printf("The elements are : %d\n", deQueue(&q));
    }

    printf(" The frnt and rear are : %d and %d", q.front, q.rear);
    


    free(q.arr);
    return 0;
}
