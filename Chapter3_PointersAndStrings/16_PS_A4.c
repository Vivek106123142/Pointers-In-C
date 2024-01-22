#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string by eliminating multiple spaces
void compressString(const char *input, char *compressed)
{
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ' || (i > 0 && input[i - 1] != ' '))
        {
            compressed[j++] = input[i];
        }
    }
    compressed[j] = '\0';
}

// Function to decompress a string by restoring spaces
void decompressString(const char *compressed, char *decompressed)
{
    int i, j;
    for (i = 0, j = 0; compressed[i] != '\0'; i++)
    {
        if (compressed[i] != ' ')
        {
            decompressed[j++] = compressed[i];
        }
        else if (i == 0 || compressed[i - 1] != ' ')
        {
            decompressed[j++] = ' ';
        }
    }
    decompressed[j] = '\0';
}

int main()
{
    char original[] = "This    is    a   sample    string   with   multiple   spaces.";
    char compressed[100];   
    char decompressed[100]; 

    // Compression
    compressString(original, compressed);
    printf("Compressed String: %s\n", compressed);

    // Decompression
    decompressString(compressed, decompressed);
    printf("Decompressed String: %s\n", decompressed);

    return 0;
}
