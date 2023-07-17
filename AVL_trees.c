#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};
int max(int a, int b);
int height(struct node* node);
struct node* newNode(int data);
struct node* rightRotate(struct node* y);
struct node* leftRotate(struct node* x);
int getBalance(struct node* node);
struct node* insert(struct node* node, int data);
void inorder(struct node* root);
void freeTree(struct node* root);

int main()
{
    struct node* root = NULL;
    int choice, data;
    while (1)
        {
        printf("1. Insert a node\n");
        printf("2. Print inorder traversal\n");
        printf("3. print preorder traversal\n");
        printf("4. print postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                if (root == NULL)
                    {
                    printf("Tree is empty.\n");
                }
                else
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;


                case 3:
                if(root==NULL)
                {
                    printf("TREE IS EMPTY\n");
                }
                else
                {
                    printf("preorder Traversal\n");
                    preorder(root);
                    printf("\n");
                }
                break;
                case 4:
                if(root==NULL)
                {
                    printf("TREE IS EMPTY\n");
                }
                else
                {
                    printf("postorder Traversal\n");
                    postorder(root);
                    printf("\n");
                }
                break;
                case 5:
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct node* rightRotate(struct node* y)
{
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct node* node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(struct node* root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);

    }
}
