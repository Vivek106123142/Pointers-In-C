#include<stdio.h>
int main(){
    char name[]="klinsman";
    int i;
    i=0;
    while(name[i])
    {
        printf("%c%c%c%c\n",name[i],*(name+i),*(i+name),i[name]);
        i++;
    }
    return 0;
}