#include<stdio.h>
int main()
{
    char name[]="Klinsman";
    char *ptr;
    ptr=name;// can be &name but name just gives address of first element in string
    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    return 0;
}