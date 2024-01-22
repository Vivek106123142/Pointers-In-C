// MAINTANING A LINKED LIST
#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
void append(struct node **, int);
void addatbeg(struct node **, int);
void addafter(struct node *, int, int);
void display(struct node *);
int count(struct node *);
void delnode(struct node **, int);
struct node *erase(struct node *);
int length(struct node *);
void addatendrec(struct node **, int);
void copy(struct node *, struct node **);
int compare(struct node*,struct node*);

int main()
{
    struct node *p, *v;
    p = NULL;
    printf("No. of elements in LL=%d\n", count(p));
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
    printf("no. of elements in LL=%d\n", count(p));
    delnode(&p, 888);
    delnode(&p, 1);
    delnode(&p, 10);
    display(p);
    printf("No. of elements in LL=%d\n", count(p));
    addatendrec(&p, 21);
    addatendrec(&p, 231);
    copy(p, &v);
    printf("the copied LL is:\n");
    display(v);
    if (compare(p, v))
        printf("both LL are equal\n");
    else
        printf("LL are different\n");
    display(p);
    display(v);
    printf("No. of elements in LL after adding at end using recursion and before erasing using recursion=%d\n", length(p));
    p = erase(p);
    printf("no. of elements after erasing=%d\n", count(p));
    return 0;
}

// ADD NODE AT END OF LL
void append(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;
    if (*q == NULL) // if list is empty create first node
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q = temp;
    }
    else
    {
        // go to last node
        while (temp->link != NULL)
            temp = temp->link;
        // add node at end
        r = (struct node *)malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

// ADD NODE AT BEGINNING OF LL
void addatbeg(struct node **q, int num)
{
    struct node *temp;
    // ADD NEW NODE
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

// add node after specific number of nodes
void addafter(struct node *q, int loc, int num)
{
    struct node *temp, *r;
    int i;
    temp = q;
    // skip to location
    while (temp->link != NULL)
    {
        temp = temp->link;
        // if end of LL is  encountered
        if (temp == NULL)
        {
            printf("there are less than %d elements in list\n", loc);
            return;
        }
    }
    // insert new node
    r = (struct node *)malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

// display content of ll
void display(struct node *q)
{
    printf("\n");
    // traverse entire ll
    while (q != NULL)
    {
        printf("%d\t", q->data);
        q = q->link;
    }
    printf("\n");
}

// count number of nodes in LL
int count(struct node *q)
{
    int c = 0;
    // traverse entire LL
    while (q != NULL)
    {
        q = q->link;
        c++;
    }
    return c;
}

// delete specified node from LL
void delnode(struct node **q, int num)
{
    struct node *old, *temp;
    temp = *q;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            // if node to be deleted is first node
            if (temp == *q)
            {
                *q = temp->link;
                // free memory
                free(temp);
                return;
            }
            // delete the intermediate nodes in LL
            else
            {
                old->link = temp->link;
                free(temp);
                return;
            }
        }
        // traverse LL till last node is reached
        else
        {
            old = temp;        // old points to previous node
            temp = temp->link; // go to next node
        }
    }
    printf("element %d not found\n", num);
}

// erasing all nodes of linked list
struct node *erase(struct node *q)
{
    struct node *temp;
    // traversing till each node is deleted
    while (q != NULL)
    {
        temp = q;
        q = q->link;
        free(temp);
    }
    return NULL;
}

// COUNTING USING RECURSION
int length(struct node *q)
{
    static int l;
    // if list is empty or if NULL is encountered
    if (q == NULL)
        return (0);
    else
    {
        // go to next node
        l = 1 + length(q->link);
        return (l);
    }
}

// adding new node at end of linked list using recursion
void addatendrec(struct node **q, int num)
{
    if (*q == NULL)
    {
        *q = (struct node *)malloc(sizeof(struct node));
        (*q)->data = num;
        (*q)->link = NULL;
    }
    else
        addatendrec(&((*q)->link), num);
}

void copy(struct node *q, struct node **s)
{
    if (q != NULL)
    {
        *s = (struct node *)malloc(sizeof(struct node));
        (*s)->data = q->data;
        (*s)->link = NULL;
        copy(q->link, &((*s)->link));
    }
}

int compare(struct node *q, struct node *r)
{
    static int flag;
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