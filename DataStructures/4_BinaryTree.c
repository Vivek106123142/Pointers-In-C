#include <stdio.h>
#include <stdlib.h>

struct btreenode
{
    struct btreenode *leftchild;
    int data;
    struct btreenode *rightchild;
};

void insert(struct btreenode **sr, int num);
void preorder(struct btreenode *root);
void inorder(struct btreenode *root);
void postorder(struct btreenode *root);

int main()
{
    struct btreenode *bt = NULL;
    int req, i = 1, num;

    printf("Specify the number of data items to be inserted: ");
    scanf("%d", &req);

    while (i++ <= req)
    {
        printf("Enter data: ");
        scanf("%d", &num);
        insert(&bt, num);
    }

    printf("\nPreorder Traversal: ");
    preorder(bt);

    printf("\nInorder Traversal: ");
    inorder(bt);

    printf("\nPostorder Traversal: ");
    postorder(bt);

    return 0;
}

void insert(struct btreenode **sr, int num)
{
    if (*sr == NULL)
    {
        *sr = (struct btreenode *)malloc(sizeof(struct btreenode));
        (*sr)->leftchild = NULL;
        (*sr)->rightchild = NULL;
        (*sr)->data = num;
        return;
    }

    if (num < (*sr)->data)
    {
        insert(&(*sr)->leftchild, num);
    }
    else
    {
        insert(&(*sr)->rightchild, num);
    }
}

void preorder(struct btreenode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void inorder(struct btreenode *root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        printf("%d ", root->data);
        inorder(root->rightchild);
    }
}

void postorder(struct btreenode *root)
{
    if (root != NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("%d ", root->data);
    }
}
