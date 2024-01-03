#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void push(struct node **, int);
int pop(struct node **);
void stack_display(struct node *);
int count(struct node *);
int main()
{
    struct node *top;
    int item;
    top = NULL; // EMPTY STACK
    push(&top, 11);
    push(&top, 12);
    push(&top, 13);
    push(&top, 14);
    push(&top, 15);
    push(&top, 16);
    push(&top, 17);
    stack_display(top);
    printf("no. of items in stack=%d\n", count(top));
    printf("items extracted from stack:\n");
    item = pop(&top);
    if (item != NULL)
        printf("%d\t", item);
    item = pop(&top);
    if (item != NULL)
        printf("%d\t                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ", item);
    item = pop(&top);
    if (item != NULL)
        printf("%d", item);
    stack_display(top);
    printf("no. of items in stack=%d\n", count(top));
    return 0;
}

// ADDING NEW ELEMENT TO TOP OF STACK
void push(struct node **s, int item)
{
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL)
    {
        printf("stack is full\n");
        return;
    }
    q->data = item;
    q->link = *s;
    *s = q;
}

// REMOVE ELEMENT FROM TOP OF STACK
int pop(struct node **s)
{
    int item;
    struct node *q;
    // if stack empty
    if (*s == NULL)
    {
        printf("stack is empty\n");
        return NULL;
    }
    else
    {
        q = *s;
        item = q->data;
        *s = q->link;
        free(q);
        return (item);
    }
}

// DISPLAY WHOLE STACK
void stack_display(struct node *q)

{
    printf("\n");
    // traverse entire LL
    while (q != NULL)
    {
        printf("%2d\t", q->data);
        q = q->link;
    }
    printf("\n");
}

// COUNT NUMBER OF NODES IN LL
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
