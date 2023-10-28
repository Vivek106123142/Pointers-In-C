#include<stdio.h>
void areaperi(int,float*,float*);
int main()
{
    int radius;
    float area,perimeter;
    printf("enter r\n");
    scanf("%d",&radius);
    areaperi(radius,&area,&perimeter);
    printf("area=%f\n",area);
    printf("perimeter=%f",perimeter);
    return 0;
}

void areaperi(int uwu,float*oniichan,float*chingping)
{
    *oniichan=3.14*uwu*uwu;
    *chingping=2*3.14*uwu;

}