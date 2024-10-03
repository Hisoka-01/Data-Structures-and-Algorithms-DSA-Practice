#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *searchRecur(struct node *ptr, int val)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    else if (ptr->data == val)
    {
        return ptr;
    }
    else if (val < ptr->data)
    {
        return searchRecur(ptr->left, val);
    }
    else
    {
        return searchRecur(ptr->right, val);
    }
}

struct node *searchIter(struct node *ptr, int val)
{
    while (ptr != NULL)
    {
        if (val == ptr->data)
        {
            return ptr;
        }
        else if (val < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    return NULL;
}

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Given value is already there in the BST \n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct node* findMin(struct node* root)
{
	while(root->left != NULL){
        root = root->left;
    }
	return root;
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    // searching for the suspecious looking BLACK nigga
    if (key < root->data)
    {
        root->left =  delete(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else   // finally got you nigga .. Don't Resist Don't Resist
    {
        if ( root->left == NULL && root->right == NULL )    // If the nigga is alone
        {
            free(root);
            return NULL;
        }
        else if ( root->left == NULL)      // if there is only nigga left 
        {
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        else if ( root->right == NULL )
        {
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    /*we can also create nodes maunally
    struct node p;
    p = (struct Node*)calloc(1,sizeof(struct Node*));
    p->data = 5;
    p->left = NULL;
    p->right = NULL;
    */
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p);
    // printf("\n");
    inOrder(p);
    printf("\n");
    // cheking if it is a bst or not
    if (!isBST(p))
    {
        printf("Not a BST \n");
    }
    else
    {
        printf("Is a BST \n");
    }
    /*searching in a bst using recursion
    printf("Enter the number u want to search in BST\n");
    int data;
    scanf("%d", &data);
    if ( searchRecur(p, data) == NULL)
    {
        printf("Value Not found \n");
    }
    else
    {
        printf("Value found\n");
    }
    */
    // insertion in a BST

    // int data;
    // printf("Enter the data you want to put in BST\n");
    // scanf("%d", &data);
    // insert(p, data);
    // inOrder(p);

    /* searching in a bst using iteration
    printf("Enter the number u want to search in BST\n");
    scanf("%d", &data);
    if (searchIter(p, data) == NULL)
    {
        printf("Value Not found \n");
    }
    else
    {
        printf("Value found\n");
    }
    */
   int del;
    printf("\nEnter the number u want to delete\n");
    scanf("%d",&del);
    delete( p, del);
    inOrder(p);

    // struct node* ptr =searchIter(p,data);
    // free(ptr);

    free(p);
    free(p1);
    free(p2);
    free(p3);
    free(p4);

    return 0;
}