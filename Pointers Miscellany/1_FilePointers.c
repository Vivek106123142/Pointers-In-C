//counting number of characters in a file
#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    int nol, noc = 0;
    fp = fopen("vivek.txt", "r");
    while (1)
    {
        ch = fgetc(fp);
        if (ch == EOF)
            break;
        noc++;
    }
    fclose(fp);
    printf("n. of characters=%d\n", noc);
    return 0;
}