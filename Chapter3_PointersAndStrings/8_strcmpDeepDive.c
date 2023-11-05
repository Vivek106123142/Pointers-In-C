#include<stdio.h>
int xstrcmp(char*,char*);
int main()
{
    char str1[50];
    char str2[50];
    int result;
    printf("enter first string");
    scanf("%s",str1);
    printf("enter second string");
    scanf("%s",str2);
    result=xstrcmp(str1,str2);
    
    if(result==0)
    {
        printf("both are same");
    }
    else if(result<0)
        printf("not the same");
    else
        printf("not same");
return 0;
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