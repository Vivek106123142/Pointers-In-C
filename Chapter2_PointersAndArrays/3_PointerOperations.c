#include<stdio.h>
int main()
{
int arr[]={10,20,30,45,67,56,74};
int i=4,*j,*k,*x,*y;
j=&i;
j=j+9;
k=&i;
k=k-3;
x=&arr[1];
y=&arr[5];
printf("%d\n",y-x);
j=&arr[4];
j=(arr+4);
if(j==k)
{
    printf("two pinters point to same location");
}
else
{
    printf("thw two pointers point to different locations");
}
return 0;
}