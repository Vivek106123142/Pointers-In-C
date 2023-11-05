#include<stdio.h>
int xstrlen(char*);
int main()
{
    char arr[50];
    printf("enter the string");
    scanf("%s",arr);
    int len1;
    len1=xstrlen(arr);
    
    printf("string=%s length=%d\n",arr,len1);
    
    return 0;
}

int xstrlen(char *s)
{
    int length=0;
    while(*s!='\0')
    {
        length++;
        s++;
    }
    return (length);
}
