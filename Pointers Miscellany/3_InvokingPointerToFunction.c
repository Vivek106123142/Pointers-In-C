#include<stdio.h>
int main()
{
    int display();
    int(*func_ptr)();
    func_ptr=display;
    printf("address of function display is %u\n",func_ptr);
    (*func_ptr)();
    func_ptr();
    return 0;
}
int display()
{
    printf("long live viruses!!\n");
    return 0;
}
//declared function display() in main and display returns an int
//int(*func_ptr)(); means that func_ptr is a pointer to a function which return int
//address of display is assigned to func_ptr thus func_ptr is a pointer to the functioin display
//(*funct_ptr)() OR func_ptr() used to call display function