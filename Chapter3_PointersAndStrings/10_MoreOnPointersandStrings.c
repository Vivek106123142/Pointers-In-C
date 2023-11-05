#include<stdio.h>
int main()
{
    char str1[]="hello";
    char *p="hello";
    //str1="bye";  THIS GIVES ERROR
    p="bye";
    return 0;
}