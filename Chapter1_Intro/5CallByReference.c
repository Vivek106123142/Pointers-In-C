#include<stdio.h>
void swapr(int*,int*);
int main()
{
    int a=10;
    int b=20;
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    swapr(&a,&b);
    printf("a=%d\n",a);
    printf("b=%d",b);
    return 0;
}
void swapr(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
