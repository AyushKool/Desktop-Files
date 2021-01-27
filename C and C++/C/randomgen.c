#include <stdio.h>
#include <stdlib.h>

int main()
{
    extern char c;
    printf("%d\n", malloc(1));
    printf("%d", &c);
}