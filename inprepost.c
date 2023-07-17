#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
int main()
{

    struct node *root;
    root=create();
     printf("Preorder traversal:\n");
preorder(root);
printf("\nInorder traversal:\n");
inorder(root);
printf("\nPostorder traversal:\n");
postorder(root);
return 0;
}


struct node *create()
{
    int n;
    struct node*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data :");
    scanf("%d",&n);
    newnode->data=n;
    printf("enter the left child of %d(if -1 ,no node)",n);
    scanf("%d", &n);
    if (n==-1)
    {
        newnode->left=NULL;
    }
    else{
    newnode->left=create();
     }
     printf("enter the right child of %d(if -1 ,no node)",n);
    scanf("%d", &n);
    if (n==-1)
    {
        newnode->right=NULL;
    }
    else{
    newnode->right=create();
     }
    return newnode;

};
void preorder(struct node *root)
{
    if(root==NULL){
        return;

    }
    printf(" %d\n",root->data);
    preorder(root->left);
    preorder(root->right);

}

void inorder(struct node *root)
{
    if(root==NULL){
        return;

    }


    inorder(root->left);
     printf(" %d\n",root->data);
    inorder(root->right);

}
void postorder(struct node *root)
{
    if(root==NULL){
        return;

    }
     postorder(root->left);
     postorder(root->right);

     printf("%d\n",root->data);


}

