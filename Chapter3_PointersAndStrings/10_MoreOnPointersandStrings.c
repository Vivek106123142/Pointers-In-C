#include<stdio.h>
#include<string.h>
int main()
{
    char str1[]="hello";
    char *p="hello";
    printf("%s\n",p);
    //str1="bye";  THIS GIVES ERROR
    p="bye";
    printf("%s",p);
    return 0;
}