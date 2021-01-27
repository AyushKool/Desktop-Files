/*
Ayush Koul
Roll No. 24
Section A

Problem Statement: Implement Stack using an Array
*/

#include <stdio.h>
#define MAX 30

void push(int *s, int *top)
{
    int num;
    printf("\nEnter number to be  pushed: ");
    scanf("%d", &num);
    (*top)++;//unary operators have right to left associativity
    s[*top] = num;
    printf("%d is pushed in Stack.\n", num);
}

void pop(int *s, int *top)
{
    printf("\n%d popped.\n", s[*top]);
    (*top)--;
}

void display(int *s, int top)
{
    ++top;
    printf("\nStack:\n");
    while (top--)
        printf("%d\n", *(s + top));
}

void main()
{
    int stack[MAX], top = -1;
    char op;
    while (1)
    {
        printf("\nEnter:\n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - display\n");
        printf("4 - exit\n");
        printf("Enter Choice: ");
        fflush(stdin);
        scanf("%c", &op);
        if (op == '1')
        {
            if (top < MAX - 1)
                push(stack, &top);
            else
                printf("\nStack is Full.\n");
        }
        else if (op == '2')
        {
            if (top != -1)
                pop(stack, &top);
            else
                printf("\nStack is Empty.\n");
        }
        else if (op == '3')
        {
            if (top != -1)
                display(stack, top);
            else
                printf("\nStack is Empty.\n");
        }
        else
            break;
    }
}