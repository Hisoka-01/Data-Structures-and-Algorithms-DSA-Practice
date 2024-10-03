#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void showTraversal(struct Node* ptr){
    struct Node*p=ptr;
    do
    {
        printf("Element is : %d\n",p->data);
        p=p->next;
    } while (p!=ptr);
    
}

struct Node* insertAtLast(struct Node* ptr, int data){
    struct Node* p=ptr;
    do
    {
        p=p->next;
    } while (p->next!=ptr);
    struct Node* q=(struct Node*)calloc(1,sizeof(struct Node*));
    q->data=data;
    q->next=p->next;
    p->next=q;
    return q;
}

int main(int argc, char const *argv[])
{
    //declearing variable
    struct Node* head;
    struct Node* second;
    struct Node* third;

    //dynamic memory allocation

    head = (struct Node*)calloc(1,sizeof(struct Node));
    second = (struct Node*)calloc(1,sizeof(struct Node));
    third = (struct Node*)calloc(1,sizeof(struct Node));

    //Linking head with second
    head->data=6;
    head->next=second;
    //Linking second with third
    second->data=9;
    second->next=third;
    //Ending third
    third->data=69;
    third->next=head; 

    // Using traversal to print every element of this Circular Linked List
    showTraversal(head);

    //Insertion using any index
    int val;
    printf("Enter the data you want to add to the lInked List at the end node :\n");
    scanf("%d",&val);
    struct Node* new=insertAtLast(head,val);
    showTraversal(head);
    free(new);
    //Other functions like deletions and insertion are similar so not doing those now
    
    free(head);
    free(second);
    free(third);

    return 0;
}
