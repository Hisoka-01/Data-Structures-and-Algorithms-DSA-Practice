#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int isEmpty(struct Node* top){
    if (top==NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(){
    struct Node* n = (struct Node*)calloc(1,sizeof(struct Node));
    if (n==NULL)
    {
        return 1;
    }
    return 0;
}

void push(struct Node** top, int val){
    if (isFull())
    {
        printf("Stack Overflow\n");
    }else{
    struct Node* n=(struct Node*)calloc(1,sizeof(struct Node));
    n->next=(*top);
    n->data=val;
    (*top)=n;
    }
}

int pop(struct Node** top){
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        struct Node* x = *top;
        int y=(*top)->data;
        (*top)=(*top)->next;
        free(x);
        return y;        
    }
}

void traversal(struct Node* top){
    struct Node* ptr=top;
    while (ptr != NULL)
    {
        printf("Element is : %d\n",ptr->data);
        ptr=ptr->next;
    } 
}

int peek(struct Node* top, int count){
    struct Node* p=top;
    for (int i = 0; i < count-1 && p!= NULL; i++)
    {
        p=p->next;
    }
    if (p!=NULL)
    {
        return p->data;
    }
    else
    {
        printf("Given Index is invalid\n");
        return -1;
    }
    
}

int stackTop(struct Node* top){
    return top->data;
}

int stackBottom(struct Node* top){
    struct Node* ptr=top;
    while (ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}

int main(int argc, char const *argv[])
{
    struct Node* top=NULL;

    //Insertion of Node

    printf("Enter the no. of element u want to enter initially in the stack : \n");
    int len;
    scanf("%d",&len);
    printf("Enter the values : \n");
    int value;
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&value);
        push(&top,value);
    }
    traversal(top);

    //Deletion of Node

    printf("Enter the no. elements you want to pop \n");
    scanf("%D",&len);
    for (int i = 0; i < len; i++)
    {
        printf("Element is : %d \n",pop(&top));
    }

    //peekinng in the stack
    printf("Enter the index at which you want to peek\n");
    scanf("%d",&len);
    printf("Value at the given indes is : %d\n",peek(top,len));

    printf("Using stack top : %d\n",stackTop(top));

    printf("Using stack bottom : %d\n",stackBottom(top));

    //Free memory

    printf("Enter the no. elements you want to pop to empty the stack\n");
    scanf("%D",&len);
    for (int i = 0; i < len; i++)
    {
        printf("Element is : %d \n",pop(&top));
    }
    
    return 0;
}
