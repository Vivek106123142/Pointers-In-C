#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void append(struct node **, int);
void addatbeg(struct node **, int);
void addafter(struct node *, int, int);
void display(struct node *);
int count();
void delnode();

int main()
{
    struct node *p;
    p = NULL;
    append(&p, 1);
    append(&p, 2);
    append(&p, 3);
    append(&p, 4);
    append(&p, 17);
    display(p);
    addatbeg(&p, 999);
    addatbeg(&p, 888);
    addatbeg(&p, 777);
    display(p);
    addafter(p, 7, 0);
    addafter(p, 2, 1);
    addafter(p, 1, 99);
    display(p);
    return 0;
}
void append(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;
    if (*q == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q = temp;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        r = (struct node *)malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

void addatbeg(struct node **q, int num)
{
    struct node *temp;
    // adding new node
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

void addafter(struct node *q, int loc, int num)
{
    struct node *temp, *r;
    int i;
    temp = q;
    // skip to desired position
    for (i = 0; i < loc; i++)
    {
        temp = temp->link;
        // if end of ll encountered
        if (temp == NULL)
        {
            printf("there are less than %d elements in list\n", loc);
            return;
        }
    }
    // Insert New Node
    r = (struct node *)malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

void display(struct node *q)
{
    printf("\n");
    // traverse LL
    while (q != NULL)
    {
        printf("%d\t", q->data);
        q = q->link;
    }
}