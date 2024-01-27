#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX 8

int visited[MAX];

struct node
{
    int data;
    struct node *next;
};

struct node *newnode;

struct node *getnode_write(int val)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL; // Initialize next pointer
    return newnode;
}

void dfs(int v, struct node **p, int n)
{
    struct node *q;
    visited[v - 1] = TRUE;
    printf("%d ", v); // Print the visited node
    q = *(p + v - 1);
    while (q != NULL)
    {
        if (visited[q->data - 1] == FALSE)
            dfs(q->data, p, n);
        q = q->next;
    }
}

int main()
{
    struct node *arr[MAX];
    struct node *v1, *v2, *v3, *v4;

    for (int i = 0; i < MAX; i++)
    {
        visited[i] = FALSE; // Initialize visited array
    }

    v1 = getnode_write(2);
    arr[0] = v1;
    v1->next = v2 = getnode_write(3);
    v2->next = NULL;

    v1 = getnode_write(1);
    arr[1] = v1;
    v1->next = v2 = getnode_write(4);
    v2->next = v3 = getnode_write(5);
    v3->next = NULL;

    v1 = getnode_write(1);
    arr[2] = v1;
    v1->next = v2 = getnode_write(6);
    v2->next = v3 = getnode_write(7);
    v3->next = NULL;

    v1 = getnode_write(2);
    arr[3] = v1;
    v1->next = v2 = getnode_write(8);
    v2->next = NULL;

    v1 = getnode_write(2);
    arr[4] = v1;
    v1->next = v2 = getnode_write(8);
    v2->next = NULL;

    v1 = getnode_write(3);
    arr[5] = v1;
    v1->next = v2 = getnode_write(8);
    v2->next = NULL;

    v1 = getnode_write(3);
    arr[6] = v1; // corrected index
    v1->next = v2 = getnode_write(8);
    v2->next = NULL;

    v1 = getnode_write(4);
    arr[7] = v1; // corrected index
    v1->next = v2 = getnode_write(5);
    v2->next = v3 = getnode_write(6);
    v3->next = v4 = getnode_write(7);
    v4->next = NULL;

    dfs(1, arr, 8);
    printf("\n"); // Print newline after DFS traversal
    return 0;
}
