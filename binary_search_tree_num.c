#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void preorder(struct node* root, FILE* fp);
void inorder(struct node* root, FILE* fp);
void postorder(struct node* root, FILE* fp);

int main() {
    FILE* fp1, *fp2, *fp3, *fp4;
    int a;

    fp1 = fopen("om.txt", "w");
    fp2 = fopen("abc.txt", "w");
    fp3 = fopen("dsa.txt", "w");
    fp4 = fopen("positive.txt", "w");
    srand(time(NULL));
    for (int i = 0; i < 7; i++) {
        a = rand() % 10;
        fprintf(fp1, "%d\n", a);
    }
    fclose(fp1);

    struct node* root = NULL;
    struct node* newNode;

    fp1 = fopen("om.txt", "r");
    while (fscanf(fp1, "%d", &a) != EOF) {
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = a;
        newNode->left = NULL;
        newNode->right = NULL;

        if (root == NULL) {
            root = newNode;
        } else {
            struct node* current = root;
            struct node* parent;
            while (1) {
                parent = current;
                if (a < current->data) {
                    current = current->left;
                    if (current == NULL) {
                        parent->left = newNode;
                        break;
                    }
                } else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = newNode;
                        break;
                    }
                }
            }
        }
    }
    fclose(fp1);

    printf("Preorder traversal:\n");
    preorder(root, fp2);
    fclose(fp2);

    printf("\nInorder traversal:\n");
    inorder(root, fp3);
    fclose(fp3);

    printf("\nPostorder traversal:\n");
    postorder(root, fp4);
    fclose(fp4);

    return 0;
}

void preorder(struct node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }

    fprintf(fp, "preorder traversal \n %d\n", root->data);
    printf("%d ", root->data);
    preorder(root->left, fp);
    preorder(root->right, fp);
}

void inorder(struct node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, fp);
    fprintf(fp, "in order traversal\n %d\n", root->data);
    printf("%d ", root->data);
    inorder(root->right, fp);
}

void postorder(struct node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }

    postorder(root->left, fp);
    postorder(root->right, fp);
    fprintf(fp, "post order traversal\n %d\n", root->data);
    printf("%d ", root->data);
}
