#include <stdlib.h>
#include <stdio.h>
struct btreenode
{
    struct btreenode *leftchild;
    int data;
    struct btreenode *rightchild;
};
void insert(struct btreenode **, int);
void inorder(struct btreenode *);
void preorder(struct btreenode *);
void postorder(struct btreenode *);

int main()
{
    struct btreenode *bt;
    int req;
    int i = 1;
    int num;
    bt = NULL; // empty tree
    printf("specify the number of data items to be inserted");
    scanf("%d", &req);
    while (i++ <= req)
    {
        printf("enter the data");
        scanf("%d", &num);
        insert(&bt, num);
    }

    printf("\nInorder Traversal\n");
    inorder(bt);
    printf("\nPostorder Traversal\n");
    preorder(bt);
    printf("\nPreorder Traversal\n");
    postorder(bt);
    return 0;
}

// insert new node into BT
void insert(struct btreenode **sr, int num)
{
    if (*sr == NULL)
    {
        *sr = (struct btreenode *)malloc(sizeof(struct btreenode));
        (*sr)->leftchild = NULL;
        (*sr)->data = num;
        (*sr)->rightchild = NULL;
        return;
    }
    else // search the node to which new node will be attached
    {
        // if data is less,traverse to left
        if (num < (*sr)->data)
            insert(&((*sr)->leftchild), num);
        else
            // traverse to right
            insert(&((*sr)->rightchild), num);
    }
}

// traverse bst in Left-Data-Right fashion
void inorder(struct btreenode *sr)
{
    if (sr != NULL)
    {
        inorder(sr->leftchild);
        // print the data of the node whose leftchild is NULL or the path has already been traversed
        printf("%d\t", sr->data);
        inorder(sr->rightchild);
    }
    else
        return;
}

void preorder(struct btreenode *sr)
{
    if (sr != NULL)
    {
        // printf the data of a node
        printf("%d\t", sr->data);
        // traverse till leftchild is not NULL
        preorder(sr->leftchild);
        // traverse till rightchild is not NULL
        preorder(sr->rightchild);
    }
    else
        return;
}

void postorder(struct btreenode *sr)
{
    if(sr!=NULL)
    {
        postorder(sr->leftchild);
        postorder(sr->rightchild);
        printf("%d\t",sr->data);
    }
    else    
        return;
}
