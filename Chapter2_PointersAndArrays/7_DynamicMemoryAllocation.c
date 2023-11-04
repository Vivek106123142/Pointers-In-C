#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n,avg,i,*p,sum=0;
    printf("enter number of students\n");
    scanf("%d",&n);
    p=(int*)malloc(n*4);
    if(p==NULL)
    {
        printf("Memory allocation unsuccesful\n");
        exit(0);
    }
    printf("Enter marks\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }
    for(i=0;i<n;i++)
    {
        sum=sum+*(p+i);
    }
        avg=sum/n;
        printf("average marks=%d\n",avg);
        return 0;
    
}