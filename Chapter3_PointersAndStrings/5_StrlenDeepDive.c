#include<stdio.h>
int xstrlen(char*);
int main()
{
    char arr[50];
    printf("enter the string");
    scanf("%s",arr);
    int len;
    len=xstrlen(&arr[0]);
    
    printf("string=%s length=%d\n",arr,len);
    
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
