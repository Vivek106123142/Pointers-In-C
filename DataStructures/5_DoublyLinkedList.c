#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *front;
    struct node *back;
};

void appendf(struct node **, int);
void appendb(struct node **, int);
void display(struct node *);
void revdisplay(struct node *);

int main()
{
    struct node *p;
    p = NULL;
    appendf(&p, 1);
    appendf(&p, 2);
    appendf(&p, 3);
    appendf(&p, 4);
    display(p);
    appendb(&p, -1);
    appendb(&p, -2);
    appendb(&p, -3);
    appendb(&p, -4);
    display(p);
    revdisplay(p);

    return 0;
}

void appendf(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;
    if (*q == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->back = NULL;
        temp->front = NULL;
        *q = temp;
    }
    else
    {
        while (temp->front != NULL)
            temp = temp->front;
        r = (struct node *)malloc(sizeof(struct node));
        r->data = num;
        r->front = NULL;
        r->back = temp; 
        temp->front = r;
    }
}

// void appendb(struct node **q, int num)
// {
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = num;
//     temp->front = NULL;
//     temp->back = NULL;

//     if (*q == NULL)
//     {
//         *q = temp;
//     }
//     else
//     {
//         temp = (struct node *)malloc(sizeof(struct node));
//         temp->data = num;
//         temp->front = *q;
//         temp->back = NULL;
//         *q = temp;
//     }
// }
void appendb(struct node **q, int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->front = NULL;
    temp->back = NULL;

    if (*q == NULL)
    {
        *q = temp;
    }
    else
    {
        struct node *last = *q;
        while (last->front != NULL)
        {
            last = last->front;
        }

        last->front = temp;
        temp->back = last;
    }
}

void addafter(struct node *q, int loc, int num)
{
    struct node *temp, *r;
    int i;
    temp = q;
    // skip to desired position
    for (i = 0; i < loc; i++)
    {
        temp = temp->front;
        // if end of ll encountered
        if (temp == NULL)
        {
            printf("There are less than %d elements in the list\n", loc);
            return;
        }
    }
    // Insert New Node
    r = (struct node *)malloc(sizeof(struct node));
    r->data = num;
    r->front = temp->front;
    r->back = temp; // Update the back pointer
    temp->front = r;
}

void display(struct node *q)
{
    printf("Original order:\n");
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->front;
    }
    printf("\n");
}


void revdisplay(struct node *q)
{
    printf("Reverse order:\n");

    // Move to the last node
    while (q->front != NULL)
    {
        q = q->front;
    }
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->back;
    }

    printf("\n");
}
