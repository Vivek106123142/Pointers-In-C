#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void addq(struct node **, struct node **, int);
int delq(struct node **, struct node **);
void display(struct node *);
int count(struct node *);
int main()
{
    struct node *front, *rear;
    int item;
    front = rear = NULL; // queue is empty
    addq(&front, &rear, 11);
    addq(&front, &rear, 12);
    addq(&front, &rear, 13);
    addq(&front, &rear, 14);
    addq(&front, &rear, 15);
    addq(&front, &rear, 16);
    addq(&front, &rear, 17);
    display(front);
    printf("no. of elements in the queue=%d\n", count(front));
    printf("items extracted frim queue:\n");
    item = delq(&front, &rear);
    if (item != NULL)
        printf("%d", item);
    item = delq(&front, &rear);
    if (item != NULL)
        printf("%d", item);
    item = delq(&front, &rear);
    if (item != NULL)
        printf("%d", item);
    printf("\n");
    display(front);
    printf("number of items in queue=%d\n", count(front));
    return 0;
}

void addq(struct node **f, struct node **r, int item)
{
    struct node *q;
    // creating new node
    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL)
    {
        printf("queue is full");
        return;
    }
    q->data = item;
    q->link = NULL;
    // IF QUEUE IS EMPTY
    if (*f == NULL)
        *f = q;
    else
        (*r)->link = q;
    *r = q;
}

// remove element from front of queue
int delq(struct node **f, struct node **r)
{
    struct node *q;
    int item;
    // if queue is empty
    if (*f == NULL)
    {
        printf("queue is empty");
        return 0;
    }
    else
    {
        // deleting node
        q = *f;
        item = q->data;
        *f = q->link;
        free(q);
        // if on deletion queue is empty
        if (*f == NULL)
            *r = NULL;
        return (item);
    }
}

// displaying the elements of queue
void display(struct node *q)
{
    // traverse the LL
    while (q != NULL)
    {
        printf("%2d\t", q->data);
        q = q->link;
    }
    printf("\n");
}

int count(struct node *q)
{
    int c = 0;
    // traversing the LL
    while (q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}