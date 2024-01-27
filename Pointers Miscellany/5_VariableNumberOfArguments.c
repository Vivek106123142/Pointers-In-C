#include <stdio.h>
#include <stdarg.h>

int findmax(int, ...);

int main()
{
    int max;
    max = findmax(5, 23, 15, 1, 92, 50);
    printf("Max=%d\n", max);
    max = findmax(3, 100, 300, 29);
    printf("Max=%d\n", max);
    return 0;
}

int findmax(int totnum, ...)
{
    int max = 0; // Initialize max to a sensible default
    int count, num;
    va_list ptr;
    va_start(ptr, totnum);
    max = va_arg(ptr, int); // Initialize max with the first argument
    for (count = 1; count < totnum; count++)
    {
        num = va_arg(ptr, int);
        if (num > max)
            max = num;
    }
    va_end(ptr);
    return max;
}
