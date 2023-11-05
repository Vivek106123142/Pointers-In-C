#include<stdio.h>
int main()
{
    char str1[]="hello";
    char str2[10];
    char *s="good morning";
    char *q;
    //str2=str1; THIS DOES NOT WORK NOT POSSIBLE!!!!!
    q=s;            //THIS DOES WORK WITH CHAR POINTERS!!!!!!!!!!
    return 0;

}