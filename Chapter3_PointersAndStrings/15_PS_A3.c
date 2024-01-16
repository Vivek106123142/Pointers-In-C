#include <stdio.h>
#include <string.h>

int main()
{
    char *names[] = {
        "santosh",
        "anmol",
        "santosh jain",
        "kishore",
        "rahul",
        "amol kumar",
        "hemant"};

    char *t;
    int i, j;

    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 7; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                t = names[i];
                names[i] = names[j];
                names[j] = t;
            }
        }
    }

    for (i = 0; i < 7; i++)
    {
        printf("%s\t", names[i]);
    }

    return 0;
}
