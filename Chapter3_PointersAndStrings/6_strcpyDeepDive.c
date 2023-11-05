#include<stdio.h>
void xstrcmp(char*,char*);
int main()
{
    char arr1[50];
    char arr2[50];
    printf("enter string");
    scanf("%s",arr1);
    xstrcmp(arr2,arr1);
    printf("%s\n",arr1);
    printf("we also now have %s",arr2);
    return 0;
}

void xstrcmp(char*t,char*s)
{
    while(*s!='\0')
    {
        *t=*s;
        s++;
        t++;
    }
    *t='\0';
}