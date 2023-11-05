#include<stdio.h>
#include<string.h>
void xstrcat(char*,char*);
int main()
{
    char str1[50];
    char str2[100];
    printf("enter the first string");
    scanf("%s",str1);
    printf("enter the second string");
    scanf("%s",str2);
    xstrcat(str2,str1);
    printf("original string:%s\n",str1);
    printf("concatenated string:%s",str2);
    return 0;
}
void xstrcat(char*str2,char*str1)
{
    char*ptr=str2+strlen(str2);
    while(*str1!='\0')
    {
        *ptr=*str1;
        ptr++;
        str1++;
    }
    *ptr='\0';
    
}