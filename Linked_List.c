#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtFirst(struct Node *key, int val)
{
    struct Node *ptr;
    ptr = (struct Node *)calloc(1, sizeof(struct Node *));
    ptr->next = key;
    ptr->data = val;
    return ptr;
}

struct Node *insertInBetween(struct Node *key, int val, int count)
{
    struct Node *ptr;
    ptr = (struct Node *)calloc(1, sizeof(struct Node *));
    struct Node *p = key;
    for (int i = 0; i < count - 1; i++)
    {
        p = p->next;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
    return ptr;
}

struct Node *insertAtLast(struct Node *key, int val)
{
    struct Node *ptr;
    ptr = (struct Node *)calloc(1, sizeof(struct Node *));
    struct Node *p = key;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

struct Node *deleteFirst(struct Node *ptr)
{
    struct Node *p = ptr->next;
    free(ptr);
    return p;
}

void deleteInBetween(struct Node *ptr, int count)
{
    struct Node *p = ptr;
    struct Node *q;
    for (int i = 0; i < count - 1; i++)
    {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}
void deleteLastNode(struct Node *ptr)
{
    struct Node *p = ptr;
    struct Node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

struct Node *deleteByValue(struct Node *ptr, int val)
{
    struct Node *p = ptr;
    struct Node *q = p->next;
    if (p->data == val)
    {
        p = ptr->next;
        free(ptr);
        return p;
    }
    else
    {
        while (q->data != val && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == val && q->next != NULL)
        {
            p->next = q->next;
            free(q);
        }
        else if (q->data == val && q->next == NULL)
        {
            p->next = NULL;
            free(q);
        }
        else
        {
            printf("Node with the given value is not found\n");
        }
        return ptr;
    }
}

void show(struct Node *key)
{
    struct Node *ptr;
    ptr = (struct Node *)calloc(1, sizeof(struct Node *));
    ptr = key;
    while (ptr != NULL)
    {
        printf("Element is :  %d\n", ptr->data);
        ptr = ptr->next;
    }
    free(ptr);
}

int main(int argc, char const *argv[])
{
    // declearing variable
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // dynamic memory allocation

    head = (struct Node *)calloc(1, sizeof(struct Node));
    second = (struct Node *)calloc(1, sizeof(struct Node));
    third = (struct Node *)calloc(1, sizeof(struct Node));

    // Linking head with second
    head->data = 6;
    head->next = second;
    // Linking second with third
    second->data = 9;
    second->next = third;
    // Ending third
    third->data = 69;
    third->next = NULL;

    // LInked list traversal to display its contents
    show(head);

    /*Linked List insertion at first
    printf("Enter the value u want to add :\n");
    int val;
    scanf("%d",&val);
    struct Node* new=insertAtFirst(head,val);
    show(new);
    free(new);
    */

    /*Linked List insertion in between
    printf("Enter the value u want to add with the index :\n");
    int val,k;
    scanf("%d%d",&val,&k);
    struct Node* new=insertInBetween(head,val,k-1);
    show(head);
    free(new);
    */

    /*Linked List insertion at last
    printf("Enter the value u want to add :\n");
    int val;
    scanf("%d",&val);
    struct Node* new=insertAtLast(head,val);
    show(head);
    free(new);
    */

    /*Linked List deletion at first
    head=deleteFirst(head);
    show(head);
    */

    /*Linked List deletion in between
    int val;
    printf("Enter the position of the linked list u want to delete\n");
    scanf("%d",&val);
    deleteInBetween(head, val);
    show(head);
    */

    /*Deletion of last NOde
    deleteLastNode(head);
    show(head);
    */

    /*Deletion of Node by its value
    int val;
    printf("Enter the value of the Node u want to delete\n");
    scanf("%d",&val);
    head=deleteByValue(head,val);
    show(head);
    */

    free(head);
    free(second);
    free(third);

    return 0;
}
