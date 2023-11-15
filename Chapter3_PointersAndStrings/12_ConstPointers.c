// #include<stdio.h>
// void xstrcpy(char*,char*);
// int main()
// {
//     char str1[]="nagpur";
//     char str2[50];
//     xstrcpy(str2,str1);
//     printf("%s\n",str2);
//     return 0;
// }
// void xstrcpy(char*t,char*s)
// {
//     while(*s !='\0')
//     {
//         *t=*s;
//         t++;
//         s++;
//     }
    
//     *t='\0';
//     s=s-6;
//     *s='K';
    
// }



#include<stdio.h>

void xstrcpy(char*, char*);

int main() {
    char str1[] = "nagpur";
    char str2[50];
    
    // Modify the original string before copying
    str1[1] = 'K';

    xstrcpy(str2, str1);
    printf("%s\n", str2);
    return 0;
}

void xstrcpy(char *t, char *s) {
    while (*s != '\0') {
        *t = *s;
        t++;
        s++;
    }

    *t = '\0';
}
