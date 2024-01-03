#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 8
int visited[8];
int q[8];
struct node
{
    int data;
    struct node *next;
};
struct node *newnode;
void dfs(int, struct node **, int);
struct node *getnode_write(int);
int main()
{
    int i;
    struct node *prtNode=NULL;
    struct node *arr[MAX];
    // struct node *getnode_write(int val);
    struct node *v1, *v2, *v3, *v4;
    {
        v1 = getnode_write(2);
        arr[0] = v1;
        v1->next = v2 = getnode_write(3);
        v2->next = NULL;
    }

    {
        v1 = getnode_write(1);
        arr[1] = v1;
        v1->next = v2 = getnode_write(4);
        v2->next = v3 = getnode_write(5);
        v3->next = NULL;
    }
    
    {
        v1 = getnode_write(1);
        arr[2] = v1;
        v1->next = v2 = getnode_write(6);
        v2->next = v3 = getnode_write(7);
        v3->next = NULL;
    }
    
    {
        v1 = getnode_write(2);
        arr[3] = v1;
        v1->next = v2 = getnode_write(8);
        v2->next = NULL;
        v1 = getnode_write(2);
    }
    
    {
        arr[4] = v1;
        v1->next = v2 = getnode_write(8);
        v2->next = NULL;
        v1 = getnode_write(3);
    }
    
    {
        arr[5] = v1;
        v1->next = v2 = getnode_write(8);
        v2->next = NULL;
        v1 = getnode_write(3);
    }
    
    {
        arr[6] = v1;
        v1->next = v2 = getnode_write(8);
        v2->next = NULL;
        v1 = getnode_write(4);
    }

    {
        arr[7] = v1;
        v1->next = v2 = getnode_write(5);
        v2->next = v3 = getnode_write(6);
        v3->next = v4 = getnode_write(7);
        v4->next = NULL;
    }

    
    for(i=0;i<=7;i++)
    {
        prtNode=arr[i];
        printf("\nindex=%d", i+1);
        while (prtNode!=NULL)
        {
            printf("\t %d",prtNode->data);
            prtNode = prtNode->next;
        }
    }
    dfs(1, arr, 8);
    return 0;
}
void dfs(int v, struct node **p, int n)
{
    struct node *q;
    visited[v - 1] = TRUE;
    printf("\n node=%d", v);
    q = *(p + v - 1);
    while (q != NULL)
    {
        if (visited[q->data - 1] == FALSE)
        {
            printf("(%d)\t",q->data);
            dfs(q->data, p, n);
        }
        else
         {
            q = q->next;
            if (q!=NULL)
            {
                printf("|%d|\t",q->data);

            }
         }   
    }
}

struct node *getnode_write(int val)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    return newnode;
}
