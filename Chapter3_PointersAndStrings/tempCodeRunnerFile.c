#include<stdio.h>
int xstrcmp(char*,char*);
int main()
{
    char str1[50];
    char str2[50];
    printf("enter first string");
    scanf("%s",str1);
    printf("enter second string");
    scanf("%s",str2);
    xstrcmp(str1,str2);
    
}
int xstrcmp(char*s1,char*s2)
{
    while(*s1==*s2)
    {
        if(*s1=='\0')
        return 0;

        s1++;
        s2++;
    }
    return(*s1-*s2);
}