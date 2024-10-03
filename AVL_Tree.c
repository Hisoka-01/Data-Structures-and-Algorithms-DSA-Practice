#include <stdio.h>
#include <stdlib.h>

struct Node // structure decleration
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *root) // finding the height of the node
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

struct Node *createNode(int key) // creation of a node
{
    struct Node *node = (struct Node *)calloc(1, sizeof(struct Node *));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int balanceFactor(struct Node *root) // finding the balance factor of the node
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

int max(int a, int b) // program to find the maximum value between two numbers
{
    return (a > b) ? a : b;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left; // storing the address in a variable
    struct Node *T = x->right;
    // right rotation
    x->right = y;
    y->left = T;
    // changing the height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right; // storing the address in a variable
    struct Node *T = y->left;
    // right rotation
    y->left = x;
    x->right = T;
    // changing the height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key) // program to insert new node in AVL tree  and rotate accordingly
{
    // checking if the root is pointing to an empty node
    if (node == NULL)
    {
        return createNode(key); // a leaf node is created
    }
    // finding the leaf node
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    // checking the balance factor and increasing the height of the tree
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = balanceFactor(node);
    // Left - Left case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // Left - Right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right - Right case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // Right - Left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct Node *root) // Preorder traversal
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
        return;
    }
}

void inOrder(struct Node *root) // inOrder traversal
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{ // postOder traversal
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

struct Node *deleteTree(struct Node *root)
{ // program to dekte the complete binary tree
    if (root != NULL)
    {
        root->left = deleteTree(root->left);                             // will first delele the left tree
        root->right = deleteTree(root->right);                           // will delete the right tree
        printf("data : %d and height : %d \n", root->key, root->height); // after both the left and right tree is deleted then delete this node
        free(root);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    struct Node *root = NULL; // variable decleration
    // inserting the values in the AVL tree
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    // priting the values in preOrder
    printf("PreOrder :\n");
    preOrder(root);
    // printing the values in Inorder
    printf("\n Inorder : \n");
    inOrder(root);
    // printing the values in Postorder
    printf(" \n PostOrder :\n");
    postOrder(root);
    // deleting the whole tree as the nodes are created by dynamic memory allocatin
    printf(" \n deleting the whole tree_bye bye green earth \n");
    root = deleteTree(root);
    // checking if the tree is actually deleted
    printf("\nLets see if inroder traversal still works \n");
    inOrder(root);

    return 0;
}
