#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("# of Args: %d", argc);
    printf("\nArgs: ");
    for(int i=0; i<argc; i++)
        printf("%s ", argv[i]);

    return 0;
    // int *p = 0xB80000000;
    // *p = "A";
}