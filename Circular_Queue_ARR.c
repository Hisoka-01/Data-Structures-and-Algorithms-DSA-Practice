#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *ptr)
{
    if ((ptr->rear + 1) % ptr->size == ptr->front)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *ptr)
{
    if ((ptr->rear == ptr->front))
    {
        return 1;
    }
    return 0;
}

void enQueue(struct Queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size;
        ptr->arr[ptr->rear] = val;
    }
}

int deQueue(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow \n");
        return -1;
    }
    else
    {
        ptr->front = (ptr->front + 1) % ptr->size;
        int val = ptr->arr[ptr->front];
        return val;
    }
}

int main(int argc, char const *argv[])
{
    struct Queue cirq; // variable declaration
    printf("Enter the size of the queue : \n");
    scanf("%d", &cirq.size);
    cirq.front = cirq.rear = 0;
    cirq.arr = (int *)calloc(cirq.size, sizeof(int));

    printf("Entere the number of elements u wwant to put in queue\n");
    int value, count;
    scanf("%d", &count);
    printf("Enter the elements\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &value);
        enQueue(&cirq, value);
    }
    printf(" The frnt and rear are : %d and %d\n", cirq.front, cirq.rear);

    // Deleltion
    printf("Entere the number of elements u wwant to take out from the queue\n");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("The elements are : %d\n", deQueue(&cirq));
    }

    printf(" The frnt and rear are : %d and %d\n", cirq.front, cirq.rear);

    printf("Entere the number of elements u wwant to put in queue\n");
    scanf("%d", &count);
    printf("Enter the elements\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &value);
        enQueue(&cirq, value);
    }
    printf(" The frnt and rear are : %d and %d\n", cirq.front, cirq.rear);
    free(cirq.arr);
    return 0;
}
