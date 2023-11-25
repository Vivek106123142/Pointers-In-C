#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
void append(struct node**,int);
int main()
{
  struct node *p; //first node always points to first node
  p=NULL;
  append(&p,1);
  append(&p,2);
  append(&p,3);
  append(&p,4);
  append(&p,17);
return 0;
}

void append(struct node **q,int num)
{
    struct node *temp,*r;
    temp=*q;
    if(*q==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=num;
        temp->link=NULL;
        *q=temp;
    }
    else
    {
        temp=*q;
        //GO TO LAST NODE
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        //ADD NODE AT END
        r=(struct node*)malloc(sizeof(struct node));
        r->data=num;
        r->link=NULL;
        temp->link=r;
    }
}