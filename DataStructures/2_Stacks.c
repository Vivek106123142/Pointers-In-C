#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
void push(struct node **, int);
int pop(struct node **);
void display(struct node *);
int count(struct node *);
int main()
{
    struct node *top;
    int item;
    top = NULL; // empty stack
    push(&top, 11);
    push(&top, 12);
    push(&top, 13);
    push(&top, 14);
    push(&top, 15);
    push(&top, 16);
    push(&top, 17);
    display(top);
    printf("no. of elements in stack=%d\n", count(top));
    printf("items extracted from stack:");
    item = pop(&top);
    if (item != NULL)
        printf("%d,", item);

    item = pop(&top);
    if (item != NULL)
        printf("%d,", item);

    item = pop(&top);
    if (item != NULL)
        printf("%d", item);
    
    display(top);
    printf("no. of items in stack=%d\n", count(top));
    return 0;
}

// add new element on top of stack
void push(struct node **s, int item)
{
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL)
    {
        printf("stack is full");
        return;
    }
    else
    {
        q->data = item;
        q->link = *s;
        *s = q; // setting new node to top
    }
}

int pop(struct node **s)
{
    int item;
    struct node *q;
    //if stack empty
    if(*s==NULL)
    {
        printf("stack is empty");
        return NULL;
    }
    else
    {
        q=*s;
        item=q->data;
        *s=q->link;
        free(q);
        return(item);
    }
}

// DISPLAY STACK
void display(struct node *q)
{
    printf("\n");
    // traverse entire ll
    while (q != NULL)
    {
        printf("%2d\t", q->data);
        q = q->link;
    }
    printf("\n");
}

// count number of nodes
int count(struct node *q)
{
    int c = 0;
    // traverse LL
    while (q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}
