#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct node
{
    int data;
    struct node *link;
};

struct node *bucks[33];

void addtolist(int, int);
void printlist(void);
int searchlists(int, int);

int main()
{
    int num, sflag;
    char ch;
    srand((unsigned)time(NULL));

    while (1)
    {
        printlist();
        printf("Do you want to generate a random number? (y/n): ");
        fflush(stdin);
        ch = tolower(getchar());

        if (ch != 'y')
            break;

        num = rand();
        printf("Random number is %d\n", num);

        sflag = searchlists(num / 1000, num);

        if (sflag)
            printf("\n%d is present in the list\n", num);
        else
        {
            printf("\n%d not present in the list\n", num);
            printf("Add it to the list? (y/n): ");
            fflush(stdin);
            ch = getchar();
            if (tolower(ch) == 'y')
                addtolist(num / 1000, num);
        }
    }
    return 0;
}


void addto(int index, int data)
{
    struct node *q, *r, *temp;
    temp = q = bucks[index];
    r = (struct node *)malloc(sizeof(struct node));
    if (r == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    r->data = data;

    // if list is empty or new data is smallest
    if (q == NULL || q->data > data)
    {
        r->link = q;
        bucks[index] = r;
        return;
    }
    
    // traverse the linked list
    while (temp->link != NULL && temp->link->data < data)
    {
        temp = temp->link;
    }

    r->link = temp->link;
    temp->link = r;
}


int searchlist(int index, int data)
{
    struct node *p;
    p = bucks[index];

    if (p == NULL)
        return 0;
    else
    {
        while (p != NULL)
        {
            if (p->data == data)
                return 1;
            else
                p = p->link;
        }
        return 0;
    }
}

void printlist(void)
{
    struct node *p;
    int i;
    printf("List:\n");
    for (i = 0; i < 33; i++)
    {
        p = bucks[i];
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->link;
        }
    }
    printf("\n");
}
