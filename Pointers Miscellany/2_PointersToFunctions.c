#include<stdio.h>
int main()
{
    int display();
    printf("address of function display is %u\n",display);
    display();//usual way of invoking function
    return 0;
}
int display()
{
    printf("Long live viruses\n");
    return 0;
}

//EVEN FUNCTIONS HAVE ADDRESSES
//THUS POINTERS CAN POINT TO FUNCTIONS(HOLD THE ADDRESS OF FUNCTIONS)
//THUS FUNCTIONS CAN BE INVOKED WITH POINTERS
//THIS PROGRAM SHOWS THAT A FUNCTION DOES HAVE AN ADDRESS