#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
void append(struct node**,int);
void addatbeg(struct node**,int);
void addafter(struct node*,int,int);
void display(struct node*);
int count(struct node *);
void delnode(struct node**,int);
int main()
{
  struct node *p; //first node always points to first node
  p=NULL;
  printf("no. of elements in ll=%d\n",count(p));
  append(&p,1);
  append(&p,2);
  append(&p,3);
  append(&p,4);
  append(&p,17);
  display(p);
  addatbeg(&p,999);
  addatbeg(&p,888);
  addatbeg(&p,777);
  display(p);
  addafter(p,7,0);
  addafter(p,2,1);
  addafter(p,1,99);
  display(p);
  printf("no. of elements in the LL=%d\n",count(p));
  delnode(&p,888);
  delnode(&p,1);
  delnode(&p,10);
  display(p);
  printf("\nnumber of elements in LL:%d\n",count(p));
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

//ADDING NEW NODE AT BEGINNING OF LL

void addatbeg(struct node**q,int num)
{
    struct node* temp;
    //adding new node
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->link=*q;
    *q=temp;
}

//ADDING NEW NODE AFTER SPECIFIED NUMBER OF NODES

void addafter(struct node *q,int loc,int num)
{
    struct node *temp,*r;
    int i;
    temp=q;
    //skipping desired portion
    for(i=0;i<loc;i++)
    {
        temp=temp->link;
        //if end of LL encountered
        if(temp==NULL)
        {
            printf("There are less than %d elements in list\n",loc);
            return;
        }
    }
    //INSERT NEW NODE
    r=(struct node*)malloc(sizeof(struct node));
    r->data=num;
    r->link=temp->link;
    temp->link=r;
}

//DISPLAY CONTENTS OF LL

void display(struct node*q)
{
    printf("\n");
    //TRAVERSE ENTIER LL
    while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->link;
    }
}

//COUNTING NO. OF NODES IN LL

int count(struct node *q)
{
    int c=0;
    //TRAVERSE LL
    while(q!=NULL)
    {
        q=q->link;
        c++;
    }
    return c;
} 

//DELETING SPECIFIC NODE FROM LL

void delnode(struct node**q,int num)
{
    struct node *old,*temp;
    temp=*q;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            //IF NODE TO BE DELETED IS FIRST NODE
            if(temp==*q)
            {
                *q=temp->link;
                //FREE THE MEMORY OCCUPIED BY NODE
                free(temp);
                return;
            }
            //DELETES INTERMEDIATE NODES IN LL
            else
            {
                old->link=temp->link;
                free(temp);
                return;
            }
        }
        //TRAVERSE THE LL TILL LAST NODE IS REACHED
        else
        {
            old=temp;//OLD NODES GO TO PREVOUS NODE
            temp=temp->link;//GO TO NEXT NODE
        }
    }
    printf("Element %d not found\n",num);
}