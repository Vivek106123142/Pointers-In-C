#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Hello world-%d",argc);

    for(int i=0;i<argc;i++)
    {
        printf("arg %d-%s\n",i,argv[i]);
    }
}

// ./(name of program) will allow us to pass arguments(here only strings)
// it is not necessay to use argc and argv, they can be anything


//./4_argcargv vivek kumar hello             (will print word on new line)
//./4_argcargv " are you doing today" "do you want to drink some tea"   (will print everything in the quotes in one line)