#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int isEmpty( struct Node* frnt){
    if ( frnt == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull( ){
    struct Node* back = NULL ;
    back = (struct Node*)calloc(1, sizeof(struct Node*)) ;
    if ( back == NULL)
    {
        return 1;
    }
    free(back);
    return 0;
}

void enQueue( struct Node** frnt, struct Node** end, int val){
    if ( isFull() )
    {
        printf("QUEUE FULL\n");
    }
    else
    {
        struct Node* new = (struct Node*)calloc(1,sizeof(struct Node*));
        new->data = val;
        new->next = NULL;
        if ( isEmpty(*frnt) )
        {
            (*frnt) = (*end) = new;
        }else
        {
            (*end)->next = new;
            (*end) = new;
        }
    }
}

int deQueue(struct Node** frnt){
    int val = -1;
    struct Node* del = *frnt;
    if ( isEmpty(*frnt) ){
        printf(" Queue Underflow\n");
        }
    else
    {
        val = (*frnt)->data;
        (*frnt) = (*frnt)->next;
        free(del);
    }
    return val;
}

int main(int argc, char const *argv[])
{
    struct Node* front = NULL ;  // variavle decleration
    struct Node* rear = NULL ;

    printf("Enter the number of elements u wwant to put in queue\n");
    int value,count;
    scanf("%d",&count);
    printf("Enter the elements\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d",&value);
        enQueue(&front, &rear, value);
    }

    //Deleltion
    printf("Entere the number of elements u wwant to take out from the queue\n");
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        printf("The elements are : %d\n", deQueue(&front));
    }

    printf("Entere the number of elements u wwant to put in queue\n");
    scanf("%d",&count);
    printf("Enter the elements\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d",&value);
        enQueue(&front, &rear, value);
    }
    //Queue deletion
    while ( front != NULL ){
        printf("The output is %d\n",deQueue(&front));
    }
    return 0;
}

/*global variable can be used instread of using pointer of pointer cause global remain throughout the program so we can use them 
throughout the progam and change their value where changes in local variable will not change the values of the variable in main cause 
locan variable has the copy of the value of that main variable*/

/* pointers of pointers are used cause :_
   Enqueue - when we change the values of frnt it doesnt reflcet in front cause front in a main variable while frnt is a local varibale
   and it has the copies of front not the address of it so to chagne the value of front we need to send its addrees
   But front is a pointer to send it adreesss we need to send a pointer of a pointer
   Dequeu - when we chnage the value of end it wont reflect in rear casue end is a local variable and it has to cpies of rear
   so to change the value of rear we will send the addrss of rear 
   */

