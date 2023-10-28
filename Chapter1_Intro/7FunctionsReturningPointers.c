#include<stdio.h>
int *fun();
int main()
{
    int *p;
    p=fun();
    printf("address of i OR p=%u\n",p);
    printf("value of i=%d\n",*p);
    return 0;
}
int *fun()
{
    static int i=20;
    return (&i);
}