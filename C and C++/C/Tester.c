#include <stdio.h>

void f(int a[])
{
    printf("%d", sizeof(a));
}

void main()
{
    // float a = 1.5;
    // double b = 1.5;
    // if(a==b)
    //     printf("Yes");
    // else
    //     printf("No");
    
    int a[] = {1,2,3,4,5};
    printf("%d\n", sizeof(a));
    f(a);
}