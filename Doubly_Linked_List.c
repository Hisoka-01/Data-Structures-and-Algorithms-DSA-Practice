#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
};

int twoWayTraversal(struct Node* ptr){
    if (ptr->next==NULL)
    {
        return ptr->data;
    }
    printf("Element is : %d\n",ptr->data);
    int val=twoWayTraversal(ptr->next);
    printf("Element is : %d\n",val);
    return ptr->data;
}

int main(int argc, char const *argv[])
{
    //variable declaration
    struct Node* head;
    struct Node* second;
    struct Node* third;

    //dynamic memory allocation

    head = (struct Node*)calloc(1,sizeof(struct Node));
    second = (struct Node*)calloc(1,sizeof(struct Node));
    third = (struct Node*)calloc(1,sizeof(struct Node));

    //Linking the Nodes

    head->prev=NULL;
    head->data=6;
    head->next=second;

    second->prev=head;
    second->data=9;
    second->next=third;

    third->prev=second;
    third->data=69;
    third->next=NULL;

    //Printng eache value by using Traversal form head to end and vice versa
    int test=twoWayTraversal(head);
    printf("Element is : %d\n",test);

    return 0;
}
