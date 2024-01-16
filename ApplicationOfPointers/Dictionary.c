#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void addtolist(int, char *);
int search_list(int, char *);
struct clist
{
    char name[20];
    struct clist *link;
} struct clist *a[26];

int main()
{
    int sflag, l;
    char country[20], ch;
    FILE *fp;
    fp = fopen("CNAMES.TXT", "r+");
    if (fp == NULL)
    {
        printf("unable to open");
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
        printf("enter country to search");
        fflush(stdin);
        gets(country);
        sflag = search_list(toupper(country[0]) - 65, country);

        if (s)
            printf("%s is present in the list\n", country);
        else
        {
            printf("Misspelled\n");
            printf("do you want to add it in the list(Y/N):"\n);
            ch = getchar();
            if (tolower(ch) == 'y')
            {
                fseek(fp, 0L, SEEK_END);
                fputs(country, fp);
                fputs("\n", fp);
                addtolist(toupper(country[0] - 65), country);
            }
        }
        printf("any more countries to search(Y/N):\n");
        fflush(stdin);
        ch = getchar();
        if (tolower(ch) != 'y')
            break;
    }
    fclose(fp);
    return 0;
}

void addtolist(int index, char *str)
{
    struct clist *q, *r, *temp;
    temp = q = a[index];
    r = (struct clist *)malloc(sizeof(struct clist));
    strcpy(r->name, str);
    // if list is empty
    if (q == NULL || strcmp(q->name, str) > 0)
    {
        q = r;
        q->link = temp;
        a[index] = q;
    }
    else
    {
        // traverse the list
        while (temp != NULL)
        {
            if (strcmp(temp->name, str) <= 0 && (strcmp(temp->link->name, str) > 0) || (temp->link == NULL))
            {
                r->link = temp->link;
                temp->link = r;
                return;
            }
            temp = temp->link;
        }
        r->link = NULL;
        temp->link = r;
    }
}

int search_list(int index, char *str)
{
    struct clist *p;
    p = a[index];
    if (p == NULL)
        return 0;
    else
    {
        while (p != NULL)
        {
            if (strcmp(p->name, str) == 0)
                return 1;
            else
                p = p->link
        }
        return 0;
    }
}[]