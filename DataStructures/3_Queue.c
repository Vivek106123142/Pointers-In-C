#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
void addq(struct node **, struct node **, int);
int delq(struct node **, struct node **);
void q_display(struct node *);
int count(struct node *);
int main()
{
    struct node *front, *rear;
    int item;
    front = rear = NULL;
    addq(&front, &rear, 11);
    addq(&front, &rear, 12);
    addq(&front, &rear, 13);
    addq(&front, &rear, 14);
    addq(&front, &rear, 15);
    addq(&front, &rear, 16);
    addq(&front, &rear, 17);
    q_display(front);
    printf("no. of items in queue=%d\n", count(front));
    printf("items extracted from queues:\n");
    item = delq(&front, &rear);
    if (item != NULL)
        printf("%d", item);
    item = delq(&front, &rear);
    if (item != NULL)
        printf("%d", item);
    printf("\n");
    q_display(front);
    printf("no. of items in queue=%d\n", count(front));
    return 0;
}

// ADDING ELEMENT TO END OF QUEUE
void addq(struct node **f, struct node **r, int item)
{
    struct node *q;
    // create new node
    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL)
    {
        printf("queue is full");
        return;
    }
    q->data = item;
    q->link = NULL;
    // if queue is empty
    if (*f == NULL)
        *f = q;
    else
        *r->link = q;
    *r = q;
}
