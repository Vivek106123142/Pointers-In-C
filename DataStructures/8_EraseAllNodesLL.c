#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void append(struct node **, int);
void display(struct node *);
int count(struct node *);
struct node *erase(struct node *);
int reclength(struct node *);
int compare(struct node *, struct node *);
int main()
{
    struct node *top;
    top = NULL;
    struct node *first, *second;
    first = second = NULL;
    append(&top, 0);
    append(&top, 1);
    append(&top, 2);
    append(&top, 3);
    append(&top, 4);
    append(&top, 5);

    if (compare(first, second))
        printf("both LL are equal");
    else
        printf("LL are Different");

    display(top);
    printf("no. of elements in LL before erasing=%d\n", count(top));
    top = erase(top);
    printf("no. of elements in LL after eraseing=%d\n", count(top));
    printf("length(recursive)=%d", reclength(top));

    return 0;
}

// add node to end of LL

void append(struct node **q, int num)
{
    struct node *temp;
    temp = *q;
    if (*q == NULL)
    {
        *q = (struct node *)malloc(sizeof(struct node));
        temp = *q;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = (struct node *)malloc(sizeof(struct node));
        temp = temp->link;
    }
    temp->data = num;
    temp->link = NULL;
}

// DISPLAY CONTENTS OF ll

void display(struct node *q)
{
    while (q != NULL)
    {
        printf("%d", q->data);
        q = q->link;
    }
}

// COUNT NODES
int count(struct node *q)
{
    int c = 0;
    while (q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}

// erase all nodes from LL
struct node *erase(struct node *q)
{
    struct node *temp = NULL;
    // traverse end erasing each node
    while (q != NULL)
    {
        temp = q;
        q = q->link;
        free(temp); // FREE MEMORY OCCUPIED BY NODE
    }
    return NULL;
}
int reclength(struct node *q)
{
    int l;
    // if list is empty or NULL encountered
    if (q == NULL)
        return 0;
    else
    {
        // go to next node
        l = 1 + reclength(q->link);
        return (l);
    }
}

int compare(struct node *q, struct node *r)
{
    int flag;
    if ((q == NULL) && (r == NULL))
        flag = 1;
    else
    {
        if ((q == NULL) || (r == NULL))
            flag = 0;
        if (q->data != r->data)
            flag = 0;
        else
            compare(q->link, r->link);
    }
    return (flag); 
}