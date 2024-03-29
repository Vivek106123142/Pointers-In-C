#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 8
struct node
{
    int data;
    struct node *next;
};
struct node *newnode;
void bfs(int, struct node **, int);
struct node *getnode_write(int);
void addqueue(int);
int deletequeue();
int isempty();
int visited[MAX];
int q[8];
int front, rear;
int main()
{
    struct node *arr[MAX];
    struct node *getnode_write(int val);
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
    }

    {
        v1 = getnode_write(2);
        arr[4] = v1;
        v1->next = v2 = getnode_write(8);
        v2->next = NULL;
    }

    {
        v1 = getnode_write(3);
        arr[5] = v1;
        v1->next = v2 = getnode_write(8);
        v2->next = NULL;
    }
    {
        v1 = getnode_write(3);
        arr[6] = v1;
        v1->next = v2 = getnode_write(8);
        v2->next = NULL;
    }

    {
        v1 = getnode_write(4);
        arr[7] = v1;
        v1->next = v2 = getnode_write(5);
        v2->next = v3 = getnode_write(6);
        v3->next = v4 = getnode_write(7);
        v4->next = NULL;
    }
    front = rear = -1;
    bfs(1, arr, 8);
    return 0;
}

void bfs(int v, struct node **p, int n)
{
    struct node *u;
    visited[v - 1] = TRUE;
    printf("%d", v);
    addqueue(v);
    while (isempty() == FALSE)
    {
        v = deletequeue();
        u = *(p + v - 1);
        while (u !=NULL)
        {
            if (visited[u->data - 1] == FALSE)
            {
                addqueue(u->data);
                visited[u->data - 1] = TRUE;
                printf("%d", u->data);
            }
            u = u->next;
        }
    }
}

struct node *getnode_write(int val)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    return newnode;
}

void addqueue(int vertex)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow");
        exit(0);
    }
    rear++;
    q[rear] = vertex;
    if (front == -1)
        front = 0;
}
int deletequeue()
{
    int data;
    if (front == -1)
    {
        printf("queue underflow");
        exit(0);
    }
    data = q[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return data;
}

int isempty()
{
    if (front == -1)
        return TRUE;
    return FALSE;
}
