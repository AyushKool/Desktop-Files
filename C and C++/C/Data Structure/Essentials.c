#include <stdio.h>

enum bool {false, true};

void print(int a)
{
    printf("%d\n", a);
}

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mult(int a, int b)
{
    return a*b;
}

void f1()
{
    printf("\nFunction 1 is called.\n");
}

void f2()
{
    printf("\nFunction 2 is called.\n");
}

void caller(void (*fcall)())
{
    fcall();
}

void main()
{
    
    // if(true)
    //     printf("hello");
    // void (*fptr)(int) = print;
    // fptr(3);

    // int a, b, op;
    // int (*fptrarr[])(int, int) = {add, sub, mult};

    // printf("Enter 2 numbers:");
    // scanf("%d%d", &a, &b);

    // printf("Enter 0 for add, 1 for subtraction, 2 for multiplication:");
    // scanf("%d", &op);

    // printf("\nAnswer = %d\n", fptrarr[op](a, b));

    caller(f1);
    caller(f2);
}