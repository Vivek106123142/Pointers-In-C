#include<stdio.h>
#include<string.h>
int main()
{
    char str1[20]="Bamboozled";
    char str2[20]="Chap";
    char str3[20];
    int l,k;
    l=strlen(str1);
    printf("length of string=%d\n",l);
    strcpy(str3,str1);
    printf("after copying,string str3=%s\n",str3);
    k=strcmp(str1,str2);
    printf("on comparing str1 and str 2,k=%d\n",k);
    k=strcmp(str3,str1);
    printf("on comparing str3 and str1,k=%d\n",k);
    strcat(str1,str2);
    printf("on concatenation str1=%s\n",str1);
    return 0;
}