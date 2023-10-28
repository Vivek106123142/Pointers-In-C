#include<stdio.h>
int main()
{
    char c,*cc;
    int i,*ii;
    float a,*aa;

    c='A';
    i=54;
    a=3.14;

    cc=&c;
    ii=&i;
    aa=&a;

    printf("address in cc=%u\n",cc);
    printf("address contained in ii=%u\n",ii);
    printf("address in aa=%u\n",aa);
    printf("value at c=%c\n",*cc);
    return 0;   
}