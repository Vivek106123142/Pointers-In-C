#include<stdio.h>
int main()
{
    float r,a;
    const float PI=3.14;
    printf("Enter radius:\n");
    scanf("%f",&r);
    a=PI*r*r;
    printf("area of circle=%f",a);
    return 0;
}