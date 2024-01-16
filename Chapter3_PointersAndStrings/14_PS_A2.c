#include <stdio.h>

char *xstrstr(char *string1, char *string2)
{
    while (*string1 != '\0')
    {
        char *tempString1 = string1;
        char *tempString2 = string2;

        // Check for substring match
        while (*tempString1 == *tempString2 && *tempString1 != '\0' && *tempString2 != '\0')
        {
            tempString1++;
            tempString2++;
        }

        // If substring found, return the starting position in string1
        if (*tempString2 == '\0')
        {
            return string1;
        }

        string1++; // Move to the next character in string1
    }

    return NULL; // Return NULL if substring is not found
}

int main()
{
    char str1[] = "Hello, World!";
    char str2[] = "yhj";

    char *result = xstrstr(str1, str2);

    if (result != NULL)
    {
        printf("Substring found at position: %ld\n", result - str1);
    }
    else
    {
        printf("Substring not found in the string.\n");
    }

    return 0;
}
