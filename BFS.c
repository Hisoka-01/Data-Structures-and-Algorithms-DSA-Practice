//This is the implementation of BSF( Breadth first Search )
//We will use queue for this implementation
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
    // Inititalizing Queue ( Circular Array Implementation )
    struct Queue queue;
    queue.size = 20;
    queue.front = queue.rear = 0;
    queue.arr = (int *)calloc(queue.size, sizeof(int *));

    // BFS Implementation
    printf("Enter the total no. of nodes in the graph\n");
    int count; // total number of the nodes in the graph
    scanf("%d", &count);

    int *visited = (int *)calloc(count, sizeof(int)); // array to check if the node has been visited or not

    int a[count][count];
    printf("Enter the graph in the adjacent matrix form : \n");
    for (int i = 0; i < count; i++) // accepting the graph in adjacent matrix form
    {
        for (int j = 0; j < count; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Printing the graph in the adjacent matrix form : \n");
    for (int i = 0; i < count; i++) // accepting the graph in adjacent matrix form
    {
        for (int j = 0; j < count; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int i; // the node we are currently at

    printf("Enter the source node\n");

    scanf("%d", &i);

    int node; // to traverse through the node

    printf(" %d ", i); // printing the source code
    visited[i] = 1;
    enQueue(&queue, i); // enqueue for exploration

    while (!isEmpty(&queue))
    {
        int node = deQueue(&queue);
        for (int j = 0; j < count; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0) // checking if the node is connected and whether its already visited or not
            {
                printf("%d ", j);   // priniing the unvisited node
                visited[j] = 1;     // marking the node as visisted
                enQueue(&queue, j); // adding the node to the queue for exploration
            }
        }
    }

    return 0;
}
