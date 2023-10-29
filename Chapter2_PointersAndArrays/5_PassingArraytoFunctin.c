#include <stdio.h>

void display1(int *, int);
void display2(int[], int);

int main()
{
    int num[] = {23, 34, 12, 44, 56, 17};
    display1(&num[0], 6);
    display2(num, 6); // Note that you don't need to use &num[0] here
    return 0;
}

void display1(int *j, int n)
{
    int i;
    for (i = 0; i < n; i++) // Use < instead of <= for array iteration
    {
        printf("element = %d\n", *j);
        j++; // increment pointer to point to the next element
    }
}

void display2(int j[], int n)
{
    int i;
    for (i = 0; i < n; i++) // Use < instead of <= for array iteration
        printf("element = %d\n", j[i]);
}
