#include <stdio.h>
#define MAX 30

int push(int s[], int top)
{
    int num;
    printf("\nEnter number to be  pushed: ");
    scanf("%d", &num);
    top++;
    s[top] = num;
    printf("%d is pushed in Stack.\n", num);
    return top;
}

int pop(int s[], int top)
{
    printf("\n%d popped.\n", s[top]);
    return top - 1;
}

void display(int s[], int top)
{
    ++top;
    printf("\nStack:\n");
    while (top--)
        printf("%d\n", s[top]);
}

void main()
{
    int stack[MAX], top = -1, op;
    while (1)
    {
        printf("\nEnter:\n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - display\n");
        printf("4 - exit\n");
        printf("Enter Choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (top < MAX - 1)
                top = push(stack, top);
            else
                printf("\nStack is Full.\n");
            break;
        case 2:
            if (top != -1)
                top = pop(stack, top);
            else
                printf("\nStack is Empty.\n");
            break;
        case 3:
            if (top != -1)
                display(stack, top);
            else
                printf("\nStack is Empty.\n");
            break;
        default:
            exit(0);
        }
    }
}