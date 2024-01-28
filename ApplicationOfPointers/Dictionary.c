#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void addtolist(int, char *);
int searchlist(int, char *);

struct clist
{
    char name[20];
    struct clist *link;
};
struct clist *a[26];
int main()
{
    int sflag, l;
    char country[20], ch;
    FILE *fp;
    fp = fopen("CNAMES.TXT", "r+");
    if (fp == NULL)
    {
        printf("Unable to Open\n");
        exit(0);
    }
    while (fgets(country, 20, fp))
    {
        l = strlen(country);
        country[l - 1] = '\0';
        addtolist(toupper(country[0]) - 65, country);
    }
    while (1)
    {
        printf("Enter the country to serach:\n");
        fflush(stdin);
        gets(country);
        sflag = search_list(toupper(country[0] - 65), country);
        if (sflag)
            printf("%s is present in the list\n", country);
        else
        {
            printf("Misspelled\n");
            printf("do you want to add it to list?(Y/N)");
            ch = getchar();
            if (tolower(ch) == 'Y')
                fseek(fp, 0L, SEEK_END);
            fputs(country, fp);
            fputs("\n", fp);
            addtolist(toupper(country[0]) - 65, country);
        }
    }
    printf("Any more countries to search(Y/N):\n");
    fflush(stdin);
    ch = getchar();
    if (tolower(ch) != 'y')
        exit;
}

void addtolist(int index,char *str)
{
    struct clist *q,*r,*temp;
    temp=q=a[index];
}
