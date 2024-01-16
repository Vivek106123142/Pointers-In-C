#include <stdio.h>

char *xstrchr(char *string, char ch)
{
    while (*string)
    {
        if (*string == ch)
        {
            return string; // Return a pointer to the first occurrence of the character
        }
        string++; // Move to the next character in the string
    }
    return NULL; // Return NULL if the character is not found
}

int main()
{
    char str[] = "yooooooo";
    char ch = 'o';

    char *result = xstrchr(str, ch);

    if (result != NULL)
    {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    }
    else
    {
        printf("Character '%c' not found in the string.\n", ch);
    }

    return 0;
}
